#ifndef _STUDENT_H_
#define _STUDENT_H_

#define MAX 24
#define START_ID 1001001

typedef struct student {
	char	name[MAX];
	int		id;
	double	gpa;     // Grade Point Average
} STUD_T;

#endif
