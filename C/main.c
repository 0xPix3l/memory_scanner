#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assets.h"

int main(void){
    printf(" ╔══════════════════════════════════════════╗\n");
    printf(" ║           Memory Scanner v1.0            ║\n");
    printf(" ╚══════════════════════════════════════════╝\n\n");

    // randomized seed
    srand(time(NULL));


    printf("[*] Allocating 1024 bytes...               OK\n");
    size_t buffer_size = 1024;
    
    unsigned char secret_key[] = {0xDE, 0xAD, 0xBE, 0xEF};          // Throw away negative numbers by using 'unsigned' char
    size_t key_size = 4;

    unsigned char *memory_space = malloc(buffer_size);
    if (memory_space == NULL) {
        printf("[!] Error: memory allocation failed. \n");
        return 1;
    }

    // Adding random values to the buffer
    printf("[*] Filling with random noise...           OK\n");
    generate_noise(memory_space, buffer_size);

    // Injecting XOR key
    printf("[*] Injecting key at a random offset...    OK\n\n");
    inject_key(memory_space, buffer_size, secret_key, key_size);


    // Scan the memory for the injected key
    printf("[~] Scanning memory block...\n");
    int flag = scan_memory(memory_space, buffer_size, secret_key, key_size);
    if (flag != -1){
        printf("Key Found at offest: 0x%X  (%d decimal)\n\n", flag, flag);
        print_hex_dump(memory_space, buffer_size);
    }
    else {
        printf("[!] FAIL: Scanner could not locate the signature.\n");
    }

    free(memory_space);
    printf("[*] Memory cleared. Test complete.\n");
}