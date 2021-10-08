#include "memory_operations.h"
#include <stdlib.h>

void* my_memcpy(void *dst, const void *src, size_t len) {
    for (int i = 0; i < len; i++) {
        ((char*) dst)[i] = ((char*) src)[i];
    }

    return dst;
}

void *my_memmove(void *dst, const void *src, size_t len) {
    char* buffer = malloc(len);
    my_memcpy(buffer, src, len);
    my_memcpy(dst, buffer, len);
    free(buffer);
    return dst;
}

int is_little_endian() {
    short int a = 0x0100;
    char* first_octet = (char*) &a;
    return !*first_octet;
}

int reverse_endianess(int value) {
    char* octets = (char*) &value;

    for (size_t i = 0; i < ((sizeof value) / 2); i++) {
        char tmp = octets[i];
        octets[i] = octets[(sizeof value) - i - 1];
        octets[(sizeof value) - i - 1] = tmp;
    }

    return value;
}
