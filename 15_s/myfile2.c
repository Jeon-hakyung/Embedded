#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s <pathname>\n", argv[0]);
        exit(1);
    }

    struct stat statbuf;
    lstat(argv[1], &statbuf);

    // 파일의 종류 얻기
    if (S_ISLINK(statbuf.st_mode)/* 심벌릭링크인가? */
        printf("%s: symbolic link\n", argv[1]);

    else if (S_ISDIR(statbuf.st_mode)/* 디렉터리인가? */
        printf("%s: directory\n", argv[1]);

    else if (/* 일반파일인가? */))
        printf("%s: regular file\n", argv[1]);

    return 0;
}
