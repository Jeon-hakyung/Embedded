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
    /* 모드 필드 추출 */
    printf("mode = %o\n", statbuf.st_mode&0777);

    /*if ((statbuf.st_mode & S_IREAD) != 0)*/
    if ((statbuf.st_mode & S_IRUSR) != 0)
        printf("user has a read permission\n");

    /*if ((statbuf.st_mode & (S_IREAD >> 3)) != 0)*/
    if ((statbuf.st_mode & S_IRGRP) != 0)
        printf("group has a read permission\n");

   /* if ((statbuf.st_mode & (S_IREAD >> 6)) != 0)*/
    if ((statbuf.st_mode & S_IROTH) != 0)
        printf("other have a read permission\n");

    return 0;
}
