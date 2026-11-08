#!/usr/bin/env python3
"""Package only public starter files; never crawl or include the private firmware."""
import argparse
from pathlib import Path
import zipfile

FILES = ("DIY_BLE.ino", "README.md", "VERSION")

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    source = Path(__file__).resolve().parent.parent / "DIY_BLE"
    contents = {}
    for name in FILES:
        path = source / name
        if path.is_symlink() or not path.is_file():
            raise SystemExit("Missing regular public source file: " + name)
        contents[name] = path.read_bytes()
    if not contents["VERSION"].strip():
        raise SystemExit("Empty version")
    args.output.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(args.output, "w", compression=zipfile.ZIP_DEFLATED) as archive:
        for name, data in contents.items():
            info = zipfile.ZipInfo("DIY_BLE/" + name, date_time=(2026, 1, 1, 0, 0, 0))
            info.compress_type = zipfile.ZIP_DEFLATED
            info.external_attr = 0o100644 << 16
            archive.writestr(info, data)
    print("Packaged " + str(args.output) + " (3 public source files)")

if __name__ == "__main__":
    main()
