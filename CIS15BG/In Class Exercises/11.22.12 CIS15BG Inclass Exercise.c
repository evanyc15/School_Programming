#include <stdio.h>
#include <stdlib.h>

void readStudent(STUDENT_STRUCT *pstu, int numScores);

int main()
{
    STUDENT_STRUCT student;
    int numScores=3;

    readStudent(&student, numScores);

// call printStudent here

    return 0;
}//end main


void readStudent(STUDENT_STRUCT *pstu, int numScores)
{
	int i;

	printf("Enter student's name: ");
	gets( pstu->name );
	printf("Enter student's ID number: ");
	scanf("%ld", &pstu->idNum);
	printf("Enter student's %d scores: \n", numScores);
	for (i = 0; i < numScores ; ++i)
		scanf("%f", &pstu->scores[i]);
} /* end readStudent */


void printStudent(const STUDENT_STRUCT *pstudent, int numScores)
{
    int i;

    printf("Student's name: %s\n", pstudent->name);
    printf("Student's ID number: %s\n", pstudent->idNum);
    printf("Student's score: ");
    for(i=0;i<numScores;++i)
    {
        printf("%5.1f",pstudent->scores[i]);
        putchar('\n');
    }
}//end printStudent
