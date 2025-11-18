#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "student.h"

int main(int argc, char* argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s file\n", argv[0]);
		exit(1);
	}

	int fd;
	
	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		perror(argv[1]);
		exit(2);
	}

	STUD_T rec;
	rec = 
	while ( 1 ) {
		if (/* fd가 가리키는 파일로부터 하나의 레코드를 rec에 읽어 들이기 */ <= 0)
			break;

		if (rec.id == 0)
			continue;

		printf("ID: %d\t NAME: %-10s\t GPA: %.1f\n", rec.id, rec.name, rec.gpa);
	}

	/* 파일 닫기 */;;
	return 0;
}
