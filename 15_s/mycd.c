#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s <pathname>\n", argv[0]);
        exit(1);
    }

    char* cwd;
    cwd = getcwd(NULL, 0);
    printf("[%s]\n", cwd);
    free(cwd);

    /* 대상 디렉터리로 작업경로 변경 */

    cwd = getcwd(NULL, 0);
    printf("[%s]\n", cwd);
    free(cwd);

    return 0;
}
