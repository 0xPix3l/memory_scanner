import random
import assets

proc injectKey*(buffer: var MemBuffer, key: MemBuffer) =
    let safe_max = len(buffer) - len(key)
    let random_offset = rand(safe_max)

    for i in 0 ..< len(key):
        buffer[random_offset + i] = key[i]