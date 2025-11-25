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
    /* 파일의 상태 정보 읽기 */
    lstat(argv[1], &statbuf);

    printf("mode = %o\n", (unsigned int)statbuf.st_mode);

    int kind = statbuf.st_mode & S_IFMT; /* 파일의 종류 얻기 */
    printf("kind = %o\n", kind);

    switch (kind) {
        case S_IFLNK:
            printf("%s: symbolic link\n", argv[1]);
            break;

        case S_IFDIR:
            printf("%s: directory\n", argv[1]);
            break;

        case S_IFREG:
            printf("%s: regular file\n", argv[1]);
            break;
    }

    return 0;
}
