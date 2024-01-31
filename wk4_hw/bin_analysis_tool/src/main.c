// main.c
#include <stdio.h>
#include <stdint.h>
#include "analyzer.h"

int main() {
    // 파일을 바이너리 모드로 읽기 전용으로 열기
    FILE *file = fopen("input.bin", "rb");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // 파일 크기 계산
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // 파일 크기가 0인 경우 경고 출력하고 프로그램 종료
    if (file_size == 0) {
        printf("Warning: File is empty.\n");
        fclose(file);
        return 0;
    }

    // 파일 내용을 저장할 배열 동적 할당
    uint8_t *buffer = (uint8_t *)malloc(file_size);
    if (!buffer) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    // 파일 내용을 배열에 읽어오기
    size_t bytesRead = fread(buffer, 1, file_size, file);
    fclose(file);

    if (bytesRead != file_size) {
        perror("Error reading file");
        free(buffer);
        return 1;
    }

    // 분석 툴을 통해 데이터 출력
    analyze(buffer, file_size);

    // 동적으로 할당한 메모리 해제
    free(buffer);

    return 0;
}

