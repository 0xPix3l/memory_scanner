/* START
  1. Calculate the maximum safe scanning index to prevent running off the cliff:
     safe_max = size - key_size

  2. Outer Loop: Create a counter 'i' starting at 0. Loop while 'i' is less than or equal to safe_max:
     
     - Create a tracking flag (e.g., match_found = true)
     
     - Inner Loop: Create a counter 'j' starting at 0. Loop while 'j' is less than key_size:
         
         Check: Does buffer[i + j] NOT equal key[j]?
         If they don't match:
           - Set match_found = false
           - Break out of the inner loop early (no point in checking the rest)
           
     - After the inner loop finishes, check our flag:
       If match_found is still true:
         - RETURN the current outer index 'i' (We found the exact start location!)

  3. If the outer loop completely finishes and found nothing:
     - RETURN -1 (A standard programming signal meaning "Not Found")
END */



#include "assets.h"
#include <stdio.h>

int scan_memory(unsigned char *buffer, size_t size, unsigned char *key, size_t key_size){
    size_t safe_max = size - key_size;

    for (size_t i = 0; i <= safe_max; i++){
        int flag = 1;

        for (size_t j = 0; j < key_size; j++){
            if (buffer[i + j] != key[j]){
                flag = 0;
                break;
            }
        }
        if (flag == 1){
            return i;
            }
    }
    return -1;
}

void print_hex_dump(unsigned char *buffer, size_t size){
    printf("  Offset   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n");
    printf("  ───────  ── ── ── ── ── ── ── ── ── ── ── ── ── ── ── ──\n");

    for (size_t i = 0; i < size; i ++) {
        if (i % 16 == 0) {
            printf("  0x%04X   ", (unsigned int)i);
        }
        printf("%02X ", buffer[i]);

        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}   