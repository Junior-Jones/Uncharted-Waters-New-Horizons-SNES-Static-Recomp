"""Split PE debug symbols and strip release metadata without recompilation.

Reject signed inputs, preserve every non-debug section byte and loader-facing
directory, and retain a detached symbol file plus a hash-bound receipt. The
original executable is never overwritten by this tool.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess

TOOLS = Path('C:/msys64/mingw64/bin')


def sha(data):
    return hashlib.sha256(data).hexdigest()


def pe_image(raw):
    assert raw[:2] == b'MZ'
    pe = struct.unpack_from('<I', raw, 60)[0]
    assert raw[pe:pe+4] == b'PE\0\0'
    machine, count = struct.unpack_from('<HH', raw, pe+4)
    assert machine == 0x8664
    symbol_offset, symbols = struct.unpack_from('<II', raw, pe+12)
    optional_size = struct.unpack_from('<H', raw, pe+20)[0]
    opt = pe+24
    assert struct.unpack_from('<H', raw, opt)[0] == 0x20b
    strings = b''
    if symbols:
        start = symbol_offset + symbols*18
        size = struct.unpack_from('<I', raw, start)[0]
        strings = raw[start:start+size]
    directory_count = struct.unpack_from('<I', raw, opt+108)[0]
    directories = [struct.unpack_from('<II', raw, opt+112+i*8)
                   for i in range(directory_count)]
    assert directories[4] == (0, 0), 'Signed PE must not be stripped implicitly'
    sections = {}
    for i in range(count):
        at = opt+optional_size+i*40
        name = raw[at:at+8].rstrip(b'\0')
        if name.startswith(b'/'):
            offset = int(name[1:])
            name = strings[offset:].split(b'\0', 1)[0]
        name = name.decode('ascii')
        virtual_size, rva, size, offset = struct.unpack_from('<IIII', raw, at+8)
        characteristics = struct.unpack_from('<I', raw, at+36)[0]
        assert name not in sections
        sections[name] = dict(virtual_size=virtual_size, rva=rva,
                              raw_bytes=size, characteristics=characteristics,
                              sha256=sha(raw[offset:offset+size]),
                              payload_sha256=sha(raw[offset:offset+min(size, virtual_size)]),
                              padding_is_zero=not any(raw[offset+min(size, virtual_size):offset+size]))
    # Exclude PE bookkeeping that legitimately changes on debug stripping:
    # initialized-data size, checksum, image size, section/symbol table offsets.
    loader = dict(machine=machine, entry=struct.unpack_from('<I', raw, opt+16)[0],
                  image_base=struct.unpack_from('<Q', raw, opt+24)[0],
                  alignments=raw[opt+32:opt+40].hex(),
                  versions=raw[opt+40:opt+52].hex(),
                  subsystem_and_dll_characteristics=raw[opt+68:opt+72].hex(),
                  stack_heap_and_loader_flags=raw[opt+72:opt+108].hex())
    return dict(sections=sections, directories=directories, loader=loader,
                symbols=symbols)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--input', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--symbols', type=Path, required=True)
    p.add_argument('--receipt', type=Path, required=True)
    a = p.parse_args()
    source = a.input.resolve()
    destinations = [v.resolve() for v in [a.output, a.symbols, a.receipt]]
    assert source not in destinations and len(set(destinations)) == 3
    assert all(not v.exists() for v in destinations), 'Never overwrite evidence'
    original = source.read_bytes()
    before = pe_image(original)
    for path in destinations:
        path.parent.mkdir(parents=True, exist_ok=True)
    commands = [
        [str(TOOLS/'objcopy.exe'), '--only-keep-debug', str(source), str(a.symbols)],
        [str(TOOLS/'strip.exe'), '--strip-all', '-o', str(a.output), str(source)],
    ]
    for command in commands:
        subprocess.run(command, check=True, capture_output=True)
    result = a.output.read_bytes()
    after = pe_image(result)
    keep = {k:v for k,v in before['sections'].items() if not k.startswith('.debug')}
    assert after['sections'].keys() == keep.keys(), 'Non-debug section selection changed'
    padding_changes = []
    for name, left in keep.items():
        right = after['sections'][name]
        for field in ['virtual_size', 'rva', 'characteristics', 'payload_sha256']:
            assert left[field] == right[field], f'Non-debug {name} {field} changed'
        if left['raw_bytes'] == right['raw_bytes']:
            assert left['sha256'] == right['sha256'], f'Non-debug {name} bytes changed'
        else:
            # GNU objcopy aligns this linker's unpadded resource payload to
            # FileAlignment. Permit only verified all-zero disk padding beyond
            # unchanged VirtualSize, never changed resource/code/data bytes.
            assert min(left['raw_bytes'], right['raw_bytes']) >= left['virtual_size']
            assert left['padding_is_zero'] and right['padding_is_zero']
            padding_changes.append(dict(section=name, before=left['raw_bytes'],
                                        after=right['raw_bytes'], zero_padding_only=True))
    assert after['loader'] == before['loader'], 'Loader ABI changed'
    for index, (left, right) in enumerate(zip(before['directories'], after['directories'])):
        assert index == 6 or left == right, f'Loader data directory {index} changed'
    assert len(before['directories']) == len(after['directories'])
    assert after['symbols'] == 0
    assert source.read_bytes() == original, 'Original executable changed'
    assert len(result) < len(original)
    receipt = dict(schema='new-horizons-v18c-release-symbol-split-v1',
                   status='PASS_NONDEBUG_SECTION_BYTES_AND_LOADER_ABI_IDENTICAL',
                   input=str(source), output=str(a.output.resolve()),
                   symbols=str(a.symbols.resolve()), commands=commands,
                   tool_sha256=sha(Path(__file__).read_bytes()),
                   strip_sha256=sha((TOOLS/'strip.exe').read_bytes()),
                   objcopy_sha256=sha((TOOLS/'objcopy.exe').read_bytes()),
                   input_sha256=sha(original), output_sha256=sha(result),
                   symbols_sha256=sha(a.symbols.read_bytes()),
                   bytes_before=len(original), bytes_after=len(result),
                   bytes_removed=len(original)-len(result),
                   symbols_bytes=a.symbols.stat().st_size,
                   removed_debug_sections=[k for k in before['sections'] if k not in keep],
                   original_coff_symbols=before['symbols'], remaining_coff_symbols=0,
                   preserved_sections=keep, zero_disk_padding_changes=padding_changes,
                   loader=after['loader'],
                   preserved_data_directories=[list(d) for i,d in enumerate(after['directories']) if i != 6],
                   runtime_code_changed=False, compilation_performed=False,
                   contexts_removed=0, runtime_logging_changed=False,
                   qualification='Structural PE equivalence, not a new gameplay or full 18C certificate')
    a.receipt.write_text(json.dumps(receipt, indent=2)+'\n')
    print(json.dumps({k:v for k,v in receipt.items() if k not in
                     ['commands','preserved_sections','loader','preserved_data_directories']}, indent=2))


if __name__ == '__main__':
    main()
