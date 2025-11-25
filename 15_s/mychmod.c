#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) // ./mychmod 0644 target
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s <mode> <pathname>\n", argv[0]);
        exit(1);
    }

	int newmode = (int) strtol(argv[1], (char **) NULL, 8);
	if (chmod(argv[2], newmode) == -1) {
		perror(argv[2]);
		exit(1);
	}

	exit(0);
}
