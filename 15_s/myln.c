#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc < 3) {
		fprintf(stderr, "usage: %s <target> <lnk_name>\n", argv[0]);
		exit(1);
	}

	if (/* 하드링크 생성 */ == -1) {
		perror(argv[0]);
		exit(2);
	}

	return 0;
}
