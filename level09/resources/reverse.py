#!/usr/bin/env python3
import sys

if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]} <encoded_string>")
    sys.exit(1)

encoded = sys.argv[1]
decoded = []
for i, c in enumerate(encoded.encode("utf-8", errors="surrogateescape")):
    decoded.append(chr(c - i))
print(''.join(decoded))
