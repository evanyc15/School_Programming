/*********************************************************
LAB 2: Student Tutoring Schedule and Hours
By: Evan Chen
April 16,2013
***********************************************************/

//NEED TO WRITE A BETTER DESCRIPTION ON FIRST LINE BEHIND LAB 2:

#define _CRT_SECURE_NO_WARNINGS 1 //Removes some warnings, take off when real testing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

#define MAX 100

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


/*1*/int readTutorStuData(Student stuRecords[],Tutor currTutor);

int main(void)
{
	Student stuRecords[MAX];
	Tutor currTutor;
	QUEUE* studentLine;
	int numStudent;
	int index = 0;
	int studentProcessed = 0;

	studentLine = createQueue();
	numStudent = readTutorStuData(stuRecords,currTutor);
	if(numStudent==0){
		printf("The file could not be read");
		return 0;
	}
	currTutor.trackTime = 9999;
	while(studentProcessed == 0){   //While loop until all students are processed
	//not sure if I need to dynamically allocate the student now or in the function
		if(stuRecords[index].time < currTutor.trackTime){
			//put function here (look at instructions)
		}
		else{
			//put function here (look at instructions)
		}

	}



	return 0;
}

/*1*/int readTutorStuData(Student stuRecords[], Tutor currTutor)
{
	FILE* fp;
	int index = 0;
	char tempName[20];
	int tempTime;
	int numStudent;
	char tempStr[20];

	fp = fopen("in.txt","r");
	if(fp==NULL){
		return 0;
	}
	
	fscanf(fp,"%d",&numStudent);
	while(((fgets(tempStr,100,fp))!=NULL)&&(index<numStudent)){
		sscanf(tempStr,"%[^,],%d",&tempName,&tempTime);
		strcpy(stuRecords[index].name,tempStr);
		stuRecords[index].time = tempTime;
		index ++;
	}
	fscanf(fp,"%s",&tempStr);		// may have to use fgets then sscanf if not reading correctly
	strcpy(currTutor.name,tempStr);   //This whole function may be wrong, I think
	return 1;					// I am parsing the read info in wrong.
}