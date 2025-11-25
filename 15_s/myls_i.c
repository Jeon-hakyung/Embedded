#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char* dir;
    if (argc == 1)
        dir = ".";
    else
        dir = argv[1];

    DIR* dp = /* 디렉터리 열기  */;
    if (dp == NULL) {
        perror(dir);
        exit(1);
    }

    struct dirent* dent;
    while (/* 디렉터리 엔트리 읽어들이기  */) {
        printf("%d %s\n", (int) dent->d_ino, dent->d_name);
    }

    /* 디렉터리 닫기 */

    return 0;
}
