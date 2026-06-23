 /*START
  1. Calculate the maximum safe starting index:
     safe_max = size - key_size

  2. Generate a random starting coordinate (offset) inside that safe zone:
     random_offset = rand() % (safe_max + 1)

  3. Loop through the key bytes from index 0 up to key_size:
     
     Inside this loop:
       Overwrite the buffer's noise at position (random_offset + current_key_index)
       with the payload byte at position (current_key_index).

end */


#include "assets.h"
#include <stdlib.h>

void inject_key(unsigned char *buffer, size_t size, unsigned char *key, size_t key_size){
    size_t safe_max = size - key_size;
    size_t random_offset = rand() % (safe_max + 1);
    
    for (size_t i = 0; i < key_size; i++){
        buffer[random_offset + i] = key[i];
    }
}




// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include "assets.h"

// int main() {
//     // Seed the randomizer
//     srand(time(NULL));

//     // 1. Define our test sizes
//     size_t test_size = 16; 
//     unsigned char target_key[] = {0xDE, 0xAD, 0xBE, 0xEF};
//     size_t key_size = sizeof(target_key);

//     // 2. Allocate and fill with clean zeros so the key pops out visually
//     unsigned char *my_buffer = malloc(test_size);
//     if (my_buffer == NULL) {
//         printf("[!] Memory allocation failed!\n");
//         return 1;
//     }
//     for (size_t i = 0; i < test_size; i++) {
//         my_buffer[i] = 0x00; 
//     }

//     printf("[*] Injecting key into clean buffer...\n");
//     inject_key(my_buffer, test_size, target_key, key_size);

//     // 3. Print the results to see the injection index
//     printf("[+] Buffer contents:\n");
//     for (size_t i = 0; i < test_size; i++) {
//         printf("%02X ", my_buffer[i]);
//     }
//     printf("\n");

//     // Clean up
//     free(my_buffer);
//     return 0;
// }