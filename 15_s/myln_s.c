#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])// ./myln_s ~/week13/15_s ~/bin
{
	if (argc < 3) {
		fprintf(stderr, "usage: %s <target> <lnk_name>\n", argv[0]);
		exit(1);
	}
	/* 심볼릭링크 생성 */
	if (symlink(argv[1],argv[2]) == -1) {
		perror(argv[0]);
		exit(2);
	}

	return 0;
}
