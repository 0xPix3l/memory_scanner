import assets
import strutils


proc scanMemory*(buffer: MemBuffer, key: MemBuffer): int =
    let safe_max = len(buffer) - len(key)

    for i in 0 ..< safe_max:
        var match = true

        for j in 0 ..< len(key):
            if buffer[i + j] != key[j]:
                match = false
                break

        if match == true:
            return i
        
    return -1


proc printHexDump*(buffer: MemBuffer) =
    echo "  Offset   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F"
    echo "  ───────  ── ── ── ── ── ── ── ── ── ── ── ── ── ── ── ──"

    for i in 0 ..< len(buffer):
        if i mod 16 == 0:
            stdout.write("  0x" & toHex(i, 4) & "   ")
        stdout.write(toHex(buffer[i].int, 2) & " ")
        if (i + 1) mod 16 == 0:
            stdout.write("\n")

    stdout.write("\n")
