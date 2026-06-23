#include <stddef.h>

#pragma once

/*
Functions:

allocate_buffer
generate_noise
inject_key
scan_memory
*/

// allocate_buffer
unsigned char *allocate_buffer(size_t size);


// generate_noise
void generate_noise(unsigned char *buffer , size_t size);

// inject key
void inject_key(unsigned char *buffer, size_t size, unsigned char *key, size_t key_size);

// scan_memory
int scan_memory(unsigned char *buffer, size_t size, unsigned char *key, size_t key_size);

// display memory dump
void print_hex_dump(unsigned char *buffer, size_t size);