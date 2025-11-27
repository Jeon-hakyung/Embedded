#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc < 3) {
		fprintf(stderr, "usage: %s <target> <lnk_name>\n", argv[0]);
		exit(1);
	}

	/* 하드링크 생성 */
	if (link(argv[1],argv[2]) == -1) {
		perror(argv[0]);
		exit(2);
	}

	return 0;
}
