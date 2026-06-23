import random
import assets

proc generateNoise*(buffer: var MemBuffer) = 
    for i in 0 ..< len(buffer):
        buffer[i] = byte(rand(255))

