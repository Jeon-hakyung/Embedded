#include <fcntl.h>		// open(), O_WRONLY, creat()
#include <unistd.h>		// close()
#include <stdio.h>
#include <stdlib.h>		// exit()

#define PERMS 0644

int main(int arg, char* argv[])
{
	int fd;
	if ((fd = open(argv[1], O_WRONLY | O_CREAT, PERMS)) == -1) {
		printf("파일 열기 오류\n");
		exit(-1);
	}

	/* fd에 "123" 쓰기 */

	printf("파일 %s 열기 성공: %d\n", argv[1], fd);

	close(fd);

	exit(0);
}
