#include <unistd.h>		// getuid()
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>

int main(void)
{
	struct passwd* pw;

	pw = /* 현재 프로세스를 실행시킨 사용자의 계정정보 가져오기 */;
	printf("UID: %d\n", (int)pw->pw_uid);
	printf("login name: %s\n", pw->pw_name);

	pw = /* 문자열 인수로 지정한 사용자의 계정정보 가져오기 */;
	printf("UID: %d\n", (int)pw->pw_uid);
	printf("login name: %s\n", pw->pw_name);

	return 0;
}
