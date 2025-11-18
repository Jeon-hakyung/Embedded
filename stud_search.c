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
	if (/* 첫번째 명령행 인자로 전달된 이름으로 읽기 용도의 파일 열기 */) {
		perror(argv[1]);
		exit(2);
	}

	STUD_T rec;
	char c;
	do {
		int id;
		printf("\nEnter student ID to search: ");
		if (scanf("%d", &id) == 1) {
			/* 해당 학번의 학생 정보 위치로 파일 포인터 이동 */;

			if ((/* fd가 가리키는 파일로부터 하나의 레코드를 rec에 읽어 들이기 */) && (rec.id != 0))
				printf("ID: %d\t Name: %-10s\t GPA: %.1f\n", rec.id, rec.name, rec.gpa);
			else
				printf("Record %d not found\n", id);
		}
		else
			printf("Input error");

		printf("Continue? (Y/N) ");
		scanf(" %c", &c);
	} while (c == 'Y' || c == 'y');

	/* 파일 닫기 */;
	return 0;
}
