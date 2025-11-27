#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s <oldpath> <newpath>\n", argv[0]);
        exit(1);
    }
    /* 이름 변경하기 */
    int rval =rename(argv[1],argv[2]);
    if (rval == -1) {
        perror(argv[0]);
        exit(2);
    }

    return 0;
}
