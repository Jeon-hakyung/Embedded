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
    stat(argv[1], &statbuf);

    printf("mode = %o\n", /* 모드 필드 추출 */);

    if ((statbuf.st_mode & S_IREAD) != 0)
        printf("user has a read permission\n");

    if ((statbuf.st_mode & (S_IREAD >> 3)) != 0)
        printf("group has a read permission\n");

    if ((statbuf.st_mode & (S_IREAD >> 6)) != 0)
        printf("other have a read permission\n");

    return 0;
}
