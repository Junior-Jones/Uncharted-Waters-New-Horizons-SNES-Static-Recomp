#!/usr/bin/env python3
"""Generate the Version 17 snapshot compatibility identity.

The identity covers the exact static-core compiler inputs and effective compile
commands plus headers/front-end boundary files that can change the serialized
machine ABI.  The generated header is intentionally excluded from its own
input set.
"""

from __future__ import annotations

import hashlib
import json
import pathlib
import re
import subprocess


ROOT = pathlib.Path(__file__).resolve().parents[1]
BUILD = ROOT / "build" / "v17c-static-gcc"
COMPILE_COMMANDS = BUILD / "compile_commands.json"
MANIFEST = ROOT / "docs" / "V17C-snapshot-build-identity.json"
HEADER = ROOT / "static-core" / "generated" / "integration" / "new_horizons_build_identity.h"

ADDITIONAL_INPUTS = [
    "CMakeLists.txt",
    "tools/generate_snapshot_build_identity.py",
    "frontend/core-api/new_horizons_static_recomp.h",
    "frontend/frontend/windows/CMakeLists.txt",
    "frontend/frontend/windows/new_horizons_app_core.c",
    "frontend/frontend/windows/new_horizons_static_recomp.h",
    "static-core/generated/scpu/nh_v07_generated.h",
    "static-core/include/new_horizons_core.h",
    "static-core/internal/new_horizons_apu.h",
    "static-core/internal/new_horizons_bus_runtime.h",
    "static-core/internal/new_horizons_bus.h",
    "static-core/internal/new_horizons_clock_domain.h",
    "static-core/internal/new_horizons_clock_port.h",
    "static-core/internal/new_horizons_cpu_io.h",
    "static-core/internal/new_horizons_dma.h",
    "static-core/internal/new_horizons_fetch.h",
    "static-core/internal/new_horizons_input.h",
    "static-core/internal/new_horizons_machine.h",
    "static-core/internal/new_horizons_math_io.h",
    "static-core/internal/new_horizons_memory.h",
    "static-core/internal/new_horizons_ppu.h",
    "static-core/internal/new_horizons_rom_identity.h",
    "static-core/internal/new_horizons_scheduler.h",
    "static-core/internal/new_horizons_scpu.h",
    "static-core/internal/new_horizons_sdsp.h",
    "static-core/internal/new_horizons_spc700_aot.h",
    "static-core/internal/new_horizons_spc700.h",
    "static-core/internal/new_horizons_sram_file.h",
    "static-core/internal/new_horizons_timing_plan.h",
]


def sha256_file(path: pathlib.Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for block in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def relative(path: pathlib.Path) -> str:
    return path.resolve().relative_to(ROOT).as_posix()


def write_if_changed(path: pathlib.Path, text: str) -> None:
    if path.is_file() and path.read_text(encoding="utf-8") == text:
        return
    path.write_text(text, encoding="utf-8", newline="\n")


def normalized_command(entry: dict[str, str]) -> str:
    command = entry["command"].replace("\\", "/")
    source_root = ROOT.as_posix()
    build_root = BUILD.as_posix()
    command = command.replace(source_root, "$SOURCE")
    command = command.replace(build_root, "$BUILD")
    command = re.sub(r"(?:^|\s)-o\s+(?:\"[^\"]+\"|\S+)", " -o $OBJECT", command)
    command = " ".join(command.split())
    return command


def compiler_abi_sizes(compiler: str) -> tuple[int, int]:
    definitions = subprocess.check_output(
        [compiler, "-dM", "-E", "-x", "c", "-"], input="",
        text=True, encoding="utf-8"
    )
    macros = {}
    for line in definitions.splitlines():
        parts = line.split(maxsplit=2)
        if len(parts) == 3 and parts[0] == "#define":
            macros[parts[1]] = parts[2]
    return int(macros["__SIZEOF_POINTER__"]), int(macros["__SIZEOF_SIZE_T__"])


def main() -> None:
    commands = json.loads(COMPILE_COMMANDS.read_text(encoding="utf-8"))
    selected = []
    for entry in commands:
        output = entry.get("output", "").replace("\\", "/")
        if "/uncharted_waters_static_core.dir/" not in output:
            continue
        source = pathlib.Path(entry["file"])
        selected.append({
            "path": relative(source),
            "sha256": sha256_file(source),
            "compile_command_sha256": hashlib.sha256(
                normalized_command(entry).encode("utf-8")
            ).hexdigest(),
        })
    selected.sort(key=lambda item: item["path"])
    if len(selected) != 2573 or len({item["path"] for item in selected}) != 2573:
        raise SystemExit("expected exactly 2,573 unique static-core compiler inputs")

    additional = []
    for name in ADDITIONAL_INPUTS:
        path = ROOT / name
        if not path.is_file():
            raise SystemExit(f"missing identity input: {name}")
        additional.append({"path": name, "sha256": sha256_file(path)})

    compiler = commands[0]["command"].split()[0].strip('"')
    compiler_version = subprocess.check_output(
        [compiler, "--version"], text=True, encoding="utf-8"
    ).splitlines()[0]
    compiler_target = subprocess.check_output(
        [compiler, "-dumpmachine"], text=True, encoding="utf-8"
    ).strip()
    pointer_bytes, size_t_bytes = compiler_abi_sizes(compiler)
    payload = {
        "schema": "new-horizons-v17c-snapshot-build-identity-v2",
        "compiler": compiler_version,
        "target": compiler_target,
        "pointer_bytes": pointer_bytes,
        "size_t_bytes": size_t_bytes,
        "selected_source_count": len(selected),
        "additional_input_count": len(additional),
        "selected_sources": selected,
        "additional_inputs": additional,
    }
    canonical = json.dumps(payload, sort_keys=True, separators=(",", ":")).encode("utf-8")
    identity = hashlib.sha256(canonical).hexdigest()
    manifest = dict(payload)
    manifest.update({
        "date": "2026-10-16",
        "sha256": identity,
        "canonical_bytes": len(canonical),
    })
    write_if_changed(MANIFEST, json.dumps(manifest, indent=2) + "\n")

    octets = ",".join(f"0x{identity[index:index + 2]}u" for index in range(0, 64, 2))
    write_if_changed(HEADER,
        "#ifndef NEW_HORIZONS_BUILD_IDENTITY_H\n"
        "#define NEW_HORIZONS_BUILD_IDENTITY_H\n\n"
        "#include <stdint.h>\n\n"
        "/* Generated by tools/generate_snapshot_build_identity.py. */\n"
        "static const uint8_t nh_v17_build_identity_sha256[32] = {\n"
        f"    {octets}\n"
        "};\n"
        f"#define NH_V17_BUILD_IDENTITY_HEX \"{identity}\"\n\n"
        "#endif\n",
    )
    print(f"identity={identity} sources={len(selected)} additional={len(additional)}")


if __name__ == "__main__":
    main()
