#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) // ./rlink /bin
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s <symbolic_link_name>\n", argv[0]);
		exit(1);
	}

	char buf[BUFSIZ];
	/*  심벌릭링크 파일의 내용 읽어오기 */
	int nread = readlink(argv[1],buf,BUFSIZ);
	if (nread == -1) {
	    perror(argv[0]);
		exit(2);
	}

	buf[nread] = '\0';
	printf("%s -> %s\n", argv[1], buf);

	return 0;
}
