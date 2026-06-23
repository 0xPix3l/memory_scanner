const
    BUFFER_SIZE* = 1024
    SECRET_KEY*  = @[byte 0xDE, 0xAD, 0xBE, 0xEF]

type
    MemBuffer* = seq[byte]
