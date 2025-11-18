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

	
	if ((fd_r = open(argv[1], O_RDONLY)) == -1) {
		perror(argv[1]);
		exit(2);
	}

	if ((fd_w = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC)) == -1) {
		perror(argv[2]);
		exit(3);
	}

	
	while ((nread = read(fd_r, buf, BUFSIZE))>0) {
		if (write(fd_w,buf,nread) < nread) {
			close(fd_r);
			close(fd_w);

			perror("File write error");
			exit(4);
		}
	}

	close(fd_r);
	close(fd_w);
	if (nread == -1) {
		perror("read error");
		exit(5);
	}

	exit(0);
}
