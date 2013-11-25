/*********************************************************
LAB 2: Student Tutoring Schedule and Hours
By: Evan Chen
April 16,2013
***********************************************************/

//NEED TO WRITE A BETTER DESCRIPTION ON FIRST LINE BEHIND LAB 2:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

#define MAX 100
#define _CRT_SECURE_NO_WARNINGS 1 //Removes some warnings, take off when real testing

typedef struct Student{
	char name[20];
	int time;
	int updateTime;
}Student;

typedef struct Tutor{
	char name[20];
	Student* studentHelped;
	int trackTime;
}Tutor;


/*1*/int readTutorStuData(Student* stuRecords[],Tutor currTutor);

int main(void)
{
	Student *stuRecords[MAX];
	Tutor currTutor;
	QUEUE* studentLine;
	int numStudent;
	int index = 0;
	int studentProcessed = 0;

	studentLine = createQueue();
	currTutor.studentHelped = NULL;
	numStudent = readTutorStuData(stuRecords,currTutor);
	if(numStudent==0){
		printf("\nThe file could not be read\n");
		return 0;
	}
	currTutor.trackTime = 9999;
	/*while(studentProcessed == 0){   //While loop until all students are processed
	//not sure if I need to dynamically allocate the student now or in the function
		if(stuRecords[index]->time < currTutor.trackTime){
			//put function here (look at instructions)
		}
		else{
			//put function here (look at instructions)
		}

	}*/



	return 0;
}

/*1*/int readTutorStuData(Student* stuRecords[], Tutor currTutor)
{
	FILE*fp;
	int index = 0;
	int numStudent;

	fp = fopen("in.txt","r");
	if(fp==NULL){
		return 0;
	}
	fscanf(fp,"%d\n",&numStudent);
	while(index<numStudent){
		stuRecords[index] = (Student*)malloc(sizeof(Student));
		fscanf(fp,"%[^,],%d\n",&(stuRecords[index]->name),&(stuRecords[index]->time));
		index ++;
	}
	fscanf(fp,"%s\n",&(currTutor.name));		// may have to use fgets then sscanf if not reading correctly  //This whole function may be wrong, I think
	
	return numStudent;					// I am parsing the read info in wrong.
}