#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#define PERMS 0755

int main(int argc, char* argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s <directory>\n", argv[0]);
		exit(1);
	}

	if (/* 디렉터리 생성 */ == -1) {
		perror(argv[1]);
		exit(2);
	}

	exit(0);
}
