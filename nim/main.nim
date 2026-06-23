import assets
import noise
import inject
import scanner
import random
import strutils


proc main() =
    echo " ╔══════════════════════════════════════════╗"
    echo " ║           Memory Scanner v1.0            ║"
    echo " ╚══════════════════════════════════════════╝"
    echo ""

    randomize()

    echo "[*] Allocating 1024 bytes...               OK"
    var buffer = newSeq[byte](BUFFER_SIZE)

    echo "[*] Filling with random noise...           OK"
    generateNoise(buffer)

    echo "[*] Injecting key at a random offset...    OK"
    injectKey(buffer, SECRET_KEY)

    echo "[~] Scanning memory block..."
    let offset  = scanMemory(buffer, SECRET_KEY)

    if offset != 1:
        echo "Key Found at offset: 0x" & toHex(offset, 2) & "  (" & $offset & " decimal)"
        echo ""
        printHexDump(buffer)
    else:
        echo "[!] FAIL: Scanner could not locate the signature."

main()