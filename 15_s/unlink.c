#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s <target>\n", argv[0]);
		exit(1);
	}

	if (/* 링크해제 */ == -1) {
		perror(argv[1]);
		exit(2);
	}

	return 0;
}
