const
    BUFFER_SIZE* = 1024
    SECRET_KEY*  = @[byte 0xDE, 0xAD, 0xBE, 0xEF]

type
    MemBuffer* = seq[byte]


# assets.nim — shared types and imports (replaces the header)
# noise.nim — fill buffer with random bytes
# inject.nim — place the key at a random offset
# scanner.nim — byte-by-byte scan + hex dump
# main.nim — wire everything together

# memory_scanner/
# ├── assets.nim        # type aliases, constants (like assets.h)
# ├── noise.nim         # generate_noise()
# ├── inject.nim        # inject_key()
# ├── scanner.nim       # scan_memory() + print_hex_dump()
# └── main.nim          # entry point