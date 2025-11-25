// 기본 실행
// chmod 4755

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(void)
{
    char* name;
    uid_t uid, euid;

    name = /* 로그인명 가져오기 */;
    uid = /* 실제 사용자 ID 가져오기 */;
    euid = /* 유효 사용자 ID 가져오기 */;

    printf("[%s] uid=%d euid=%d\n", name, (int)uid, (int)euid);

    return 0;
}
