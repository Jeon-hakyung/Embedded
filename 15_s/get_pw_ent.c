#include <pwd.h>
#include <stdio.h>

int main(void)
{
	struct passwd* pw;

	while ((pw = /* passwd 항목 가져오기 */)) != NULL) 
		printf("%s(%d)\n", pw->pw_name, (int)pw->pw_uid);

	return 0;
}
