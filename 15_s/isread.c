#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern int errno;

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s <pathname>\n", argv[0]);
        exit(1);
    }

    if (/* 대상 파일이 존재하지 않으면 */) {
        printf("%s: file not exist.\n", argv[1]);
        exit(2);
    }

    int perm = /* 대상 파일에 읽기 권한이 있으면 */;
    if (perm == 0)
        printf("%s: read permmission is permmitted.\n", argv[1]);
    else if (perm == -1 && errno == EACCES)
        printf("%s: read permmission is not permmitted.\n", argv[1]);

    return 0;
}
