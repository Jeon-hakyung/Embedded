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

	if ((fp= fopen(argv[1], "r") ==NULL ) {
		perror(argv[1]);
		exit(1);
	}

	while ((nread = fscanf(fp, "%[^\n]\n", buf)) != EOF) {
			frpintf(stdout, "%s\n", buf);
	}
	fclose(fp);

	exit(0);
}
