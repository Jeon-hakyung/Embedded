#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main() {
    char* filename = "test.txt";
    char* data = "Hello, this is a test file for lseek!";

    // 파일 생성 및 데이터 쓰기
    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("파일 열기 실패: %s\n", strerror(errno));
        exit(1);
    }

    // 데이터 쓰기
    write(fd, data, strlen(data));

    /* 파일의 시작으로 이동 (SEEK_SET) */
    printf("1. 파일 시작으로 이동: %ld\n", (long) offset);

    /* 현재 위치에서 5바이트 앞으로 이동 (SEEK_CUR) */
    printf("2. 현재 위치에서 5바이트 이동: %ld\n", (long) offset);

    char buff;
    read(fd, &buff, 1);
    printf("3. 현재 위치의 데이터 읽기: %c\n", buff);

    /* 파일 끝에서 10바이트 뒤로 이동 (SEEK_END) */
    printf("4. 파일 끝에서 10바이트 뒤로 이동: %ld\n", (long) offset);

    // 현재 위치에서 데이터 읽기
    char buffer[100] = { '\0' };
    read(fd, buffer, 10);
    printf("5. 현재 위치의 데이터 읽기: %s\n", buffer);

    // 파일 닫기
    close(fd);

    return 0;
}
