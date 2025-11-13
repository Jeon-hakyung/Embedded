#include <fcntl.h>		// open(), O_WRONLY
#include <unistd.h>		// close()
#include <stdio.h>
#include <stdlib.h>		// exit()

int main(int arg, char* argv[]) // ./opentest target
{
	int fd;

	
	if ((fd=open(argv[1],O_RDONLY )) == -1) {
		printf("error\n");
		exit(-1);
	}

	printf("File %s open: %d\n", argv[1], fd);

	close(fd);

	exit(0);
}
