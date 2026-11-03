"""Check the public export without requiring a ROM or personal build paths."""
from pathlib import Path
import csv
import hashlib
import re

root = Path(__file__).resolve().parents[1]
for row in csv.DictReader((root/'SOURCE-MANIFEST.csv').open(encoding='utf-8')):
    path = root/row['path']
    assert path.is_file(), f"Missing source: {row['path']}"
    assert hashlib.sha256(path.read_bytes()).hexdigest() == row['sha256'], row['path']
for path in root.rglob('*'):
    if not path.is_file() or any(p in ('.git', 'build', '__pycache__') for p in path.relative_to(root).parts):
        continue
    data = path.read_bytes()
    # Preserve SDL's documented fictitious "bob" example verbatim.
    if path.relative_to(root).as_posix() == 'third_party/SDL3/include/SDL3/SDL_filesystem.h':
        data = re.sub(rb'[A-Za-z]:[/\\]+Users[/\\]+bob[/\\]', b'example/', data)
    # Construct the pattern so this checker doesn't flag its own source.
    private = rb'[A-Za-z]:' + rb'[/\\]+Users[/\\]'
    assert not re.search(private, data, re.I), f"Private drive path: {path.relative_to(root)}"
    assert not re.search(private, data.replace(b'\0',b''), re.I), f"Private UTF-16 path: {path.relative_to(root)}"
    assert path.suffix.lower() not in ('.smc', '.sfc', '.sav', '.srm', '.nhsnap', '.exe', '.dll', '.obj', '.pdb'), path
print('PASS: source manifest, no private drive paths, no ROMs or personal runtime data')
