// analyzer.c
#include <stdio.h>
#include <stdint.h>
#include "analyzer.h"

void analyze(const uint8_t *buffer, size_t size) {
    // xxd 스타일로 데이터 출력
    printf("Offset(h)   | 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f\n");
    printf("--------------------------------------------------------\n");

    size_t offset = 0;
    for (size_t i = 0; i < size; i++) {
        if (i % 16 == 0) {
            if (i != 0) {
                printf("\n");
            }
            printf("%08zx: ", offset);
            offset += 16;
        }
        printf("%02x ", buffer[i]);
    }
    printf("\n");
}

