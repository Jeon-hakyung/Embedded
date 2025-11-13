#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024
#define PERMS 0644

int main(int argc, char* argv[])
{
	char buf[BUFSIZE];
	int fd_r, fd_w;
	ssize_t nread;

	if (argc != 3) {
		fprintf(stderr, "usage: %s file1 file2\n", argv[0]);
		exit(1);
	}

	if ((fd_r = /* argv[1]을 읽기 모드로 열기 */) == -1) {
		perror(argv[1]);
		exit(2);
	}

	if ((fd_w = /* argv[2]를 쓰기 모드로 열기 */) == -1) {
		perror(argv[2]);
		exit(3);
	}

	while (/* fd_r에서 buf로 읽어 들이기 */) {
		if (/* fd_w에 buf예 쓰기 */ < nread) {
			close(fd_r);
			close(fd_w);

			perror("write error");
			exit(4);
		}
	}

	/* 모든 파일 닫기 */

	if (nread == -1) {
		perror("read error");
		exit(5);
	}

	exit(0);
}
