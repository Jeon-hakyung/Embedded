#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char* argv[])
{
	char buf[BUFSIZE];
	int fd;
	ssize_t nread;

	if (/* fd = 읽기 모드로 파일 열기 */) {
		perror(argv[1]);
		exit(1);
	}

	while (/* fd로부터 buf에 읽어들이기 */)
		/* buf의 내용을 표준출력에 쓰기 */

	/* 파일 닫기 */

	exit(0);
}
