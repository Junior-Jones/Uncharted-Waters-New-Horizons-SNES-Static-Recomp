"""Package the current source checkout and an already-qualified Windows EXE.

Uses the existing release layout, explicit runtime allowlist, SHA-256 manifests
and ZIP verification. Does not export older research source over this checkout.
"""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import re
import shutil
import subprocess
import zipfile

ROOT = Path(__file__).resolve().parents[1]
RUNTIME = ('Launcher.exe', 'recomplauncher.json', 'README.txt', 'VERSION.txt',
           'SDL-LICENSE.txt', 'THIRD-PARTY-NOTICES.txt')


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def manifest(path, base, files):
    with path.open('w', encoding='utf-8', newline='') as stream:
        writer = csv.writer(stream, lineterminator='\n')
        writer.writerow(('path', 'sha256', 'bytes'))
        for file in files:
            writer.writerow((file.relative_to(base).as_posix(), digest(file), file.stat().st_size))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--executable', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--version', required=True)
    args = parser.parse_args()
    assert re.fullmatch(r'\d+\.\d+\.\d+', args.version)
    exe = args.executable.resolve()
    output = args.output.resolve()
    assert exe.is_file() and exe.read_bytes()[:2] == b'MZ'
    version = (ROOT / 'VERSION.txt').read_text(encoding='utf-8')
    assert f'Version: {args.version}\n' in version
    assert digest(exe) in version and f'Launcher.exe size: {exe.stat().st_size} bytes' in version
    for folder in ('Release', 'Test'):
        destination = output / folder
        destination.mkdir(parents=True, exist_ok=True)
        for name in RUNTIME:
            shutil.copy2(exe if name == 'Launcher.exe' else ROOT / name, destination / name)
    release = output / 'Release'
    runtime_files = [release / name for name in RUNTIME]
    manifest(ROOT / 'RELEASE-MANIFEST.csv', release, runtime_files)
    shutil.copy2(ROOT / 'RELEASE-MANIFEST.csv', output / 'RELEASE-MANIFEST.csv')
    names = subprocess.check_output(
        ['git', 'ls-files', '-z', '--cached', '--others', '--exclude-standard'], cwd=ROOT
    ).decode('utf-8').split('\0')
    names = sorted(set(name for name in names if name and name not in
                       ('SOURCE-MANIFEST.csv', 'RELEASE-MANIFEST.csv')), key=str.casefold)
    files = [ROOT / name for name in names]
    for file in files:
        assert file.is_file(), file
        assert not any(part in ('.git', 'build', '__pycache__') for part in file.relative_to(ROOT).parts)
        assert file.suffix.lower() not in ('.exe', '.dll', '.smc', '.sfc', '.sav', '.srm', '.nhsnap', '.pdb', '.zip')
    manifest(ROOT / 'SOURCE-MANIFEST.csv', ROOT, files)
    archives = []
    for kind, base, members in (
        ('Windows-x64', release, runtime_files),
        ('Source', ROOT, files + [ROOT / 'SOURCE-MANIFEST.csv', ROOT / 'RELEASE-MANIFEST.csv']),
    ):
        target = output / f'Uncharted-Waters-New-Horizons-{args.version}-{kind}.zip'
        with zipfile.ZipFile(target, 'w', zipfile.ZIP_DEFLATED, compresslevel=6) as archive:
            for file in members:
                archive.write(file, file.relative_to(base).as_posix())
        with zipfile.ZipFile(target) as archive:
            assert archive.testzip() is None
            for name in archive.namelist():
                assert hashlib.sha256(archive.read(name)).hexdigest() == digest(base / name), name
            if kind == 'Windows-x64':
                assert set(archive.namelist()) == set(RUNTIME)
        archives.append({'path': target.name, 'bytes': target.stat().st_size, 'sha256': digest(target)})
    for name in RUNTIME:
        assert digest(output / 'Test' / name) == digest(release / name)
    receipt = {'version': args.version, 'exe_sha256': digest(exe),
               'exe_bytes': exe.stat().st_size, 'release_files': len(RUNTIME),
               'source_files': len(files) + 2, 'archives': archives,
               'personal_test_settings_and_saves_preserved': True, 'rom_included': False}
    (output / f'PACKAGE-RECEIPT-{args.version}.json').write_text(json.dumps(receipt, indent=2) + '\n')
    (output / f'SHA256SUMS-{args.version}.txt').write_text(
        ''.join(f"{item['sha256']}  {item['path']}\n" for item in archives))
    print(json.dumps(receipt, indent=2))


if __name__ == '__main__':
    main()
