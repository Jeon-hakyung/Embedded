#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FILENAME "dup_test"

int main(void)
{
	int fd, fd_cp;

	if ((fd = creat(FILENAME, 0600)) == -1)
		perror(FILENAME);

	write(fd, "Hello", 6);

	fd_cp = /* fd 복사하기 */;

	write(fd_cp, "World\n", 6);

	exit(0);
}
