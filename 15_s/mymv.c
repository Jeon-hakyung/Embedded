#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s <oldpath> <newpath>\n", argv[0]);
        exit(1);
    }

    int rval = /* 이름 변경하기 */;
    if (rval == -1) {
        perror(argv[0]);
        exit(2);
    }

    return 0;
}
