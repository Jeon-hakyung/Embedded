#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "student.h"

int main(int argc, char* argv[]) // ./create mydb 
{
	int fd;
	STUD_T rec;

	if (argc < 2) {
		fprintf(stderr, "usage: %s file\n", argv[0]);
		exit(1);
	}

	
	if ((fd = open(argv[1], O_WRONLY | O_CREAT, 0644)) == -1 ) {
		perror(argv[1]);
		exit(2);
	}

	printf("%-9s %-13s %-4s\n", "ID", "NAME", "GPA");
	while (scanf("%d %s %lf", &rec.id, rec.name, &rec.gpa) == 3) {
		
		 
		lseek(fd, (rec.id - START_ID) * sizeof rec , SEEK_SET );
		/* fd가 가리키는 파일에 rec 저장 */;
		write(fd, &rec, sizeof(rec)); 
	}


	/* 파일 닫기 */;
	close(fd);
	return 0;
}
