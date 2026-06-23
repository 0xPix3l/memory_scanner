/* 
START
  Loop: Create a counter starting at 0. Keep looping as long as the counter is less than 'size'.
    
    Inside the loop for each step:
      1. Calculate a random number using the built-in random function.
      2. Use the modulo operator ( % 256 ) on that number to safely trap it between 0 and 255.
      3. Access the 'buffer' at the exact position of your current counter.
      4. Drop that trapped, 1-byte random number into that slot.
      
    Advance the counter by 1 and repeat until the buffer is full.
END
*/

#include "assets.h"
#include <stdio.h>
#include <stdlib.h>



void generate_noise(unsigned char *buffer , size_t size) {
    for (size_t i = 0; i < size; i++){
        int value = rand();
        buffer[i] = value % 256;

    }

}




// Testing

// #include <time.h>

// int main() {
//     srand(time(NULL));
//     size_t test_size = 1024;

    
//     printf("[*] Testing memory allocation...\n");
//     unsigned char *my_buffer = malloc(test_size);
    
//     if (my_buffer == NULL) {
//         printf("[!] Failed to allocate memory!\n");
//         return 1;
//     }

//     printf("[*] Running generate_noise...\n");
//     generate_noise(my_buffer, test_size);

//     printf("[+] Printing first 16 bytes of noise:\n");
//     for (size_t i = 0; i < 16; i++) {
//         // %02X prints 2-digit uppercase Hex number
//         printf("%02X ", my_buffer[i]); 
//     }
//     printf("\n\n");

//     // Clean up heap memory
//     free(my_buffer);
//     printf("[+] Test complete. Memory freed.\n");
    
//     return 0;
// }