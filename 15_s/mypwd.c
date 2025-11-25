#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char* cwd;
    char buf1[BUFSIZ];
    char buf2[10];

    printf("BUFSIZ=%d\n", BUFSIZ);

    cwd = /* buf1에 현재 작업 경로 얻기 */
    printf("#1: [%s]\n", buf1);
    printf("#1: [%s]\n", cwd);

    cwd = /* BUFSIZ 크기의 배열 동적할당하여 현재 작업 경로 저장후 반환 */
    printf("#2: [%s]\n", cwd);
    free(cwd);

    cwd = /* 현재 작업 경로를 저장한 메모리를 동적할당하여 반환 */
    printf("#3: [%s]\n", cwd);
    free(cwd);

    cwd = getcwd(buf2, 10);
    if (cwd == NULL) {
        perror("mypwd");
        exit(1);
    }
    printf("#4: [%s]\n", cwd);

    return 0;
}
