/*********************************************************
LAB 2: Student Tutoring Schedule and Hours
By: Evan Chen
April 16,2013
***********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

#define MAX 100
#define _CRT_SECURE_NO_WARNINGS 1 //Removes some warnings, take off when real testing

typedef struct Student{
	char name[20];
	int enterTime;
	int updateTime;
}Student;

typedef struct Tutor{
	char name[20];
	Student* studentHelped;
	int doneTime;
}Tutor;

typedef struct Stats{
	int qLength;
	int qTime;
}Stats;


/*1*/int readTutorStuData(Student* stuRecords[],Tutor* currTutor);
/*2*/void studentearlierQueue(Student* currStudent,Tutor* currTutor,QUEUE* studentLine,STACK* lineInfo);
/*3*/int tutorDoneStudent(Student* currStudent,Tutor* currTutor,QUEUE* studentLine,STACK* lineInfo);
/*4*/void printlineStats(STACK* lineInfo);

int main(void)
{
	Student *stuRecords[MAX];
	Student* currStudent;
	Tutor* currTutor;
	QUEUE* studentLine;
	STACK* lineInfo;
	int numStudent;
	int index = 0;
	int studentProcessed = 1;
	int queueStatus;

	studentLine = createQueue();
	lineInfo = createStack();
	currTutor = (Tutor*)malloc(sizeof(Tutor));
	currTutor->studentHelped = NULL;
	currTutor->doneTime = 9999;
	numStudent = readTutorStuData(stuRecords,currTutor);
	if(numStudent == 0){
		printf("File cannot open\n");
		return 0;
	}
	//printf("\nThis is tutor trackTime: %d \n",currTutor->doneTime);
	while(index<numStudent && (studentProcessed == 1)){ // just for trial, index< 4 have to change
		currStudent = stuRecords[index];
		if((currStudent->enterTime)<(currTutor->doneTime)){
			studentearlierQueue(currStudent,currTutor,studentLine,lineInfo);
			index++;
		}
		else if((currTutor->doneTime)<=(currStudent->enterTime)){ //When tutor is helping no student
			queueStatus = tutorDoneStudent(currStudent,currTutor,studentLine,lineInfo);
			studentProcessed == queueStatus;
			if(queueStatus == 1){
				//printf("Student %s is done at time %d, wait time: %d\n",(currStudent->name),(currTutor->doneTime),
					//(currStudent->updateTime - currStudent->enterTime));
				if(index!=numStudent){
				index++;
				}
			}
		} 
	}
	printf("Simulation done\n\n");
	destroyQueue(studentLine); //May cause memory leak so double check
	printlineStats(lineInfo); //Not Done
	destroyStack(lineInfo);

	return 0;
}

/*1*/int readTutorStuData(Student* stuRecords[], Tutor* currTutor)
{
	FILE*fp;
	int i;
	int numStudent;

	fp = fopen("in.txt","r");
	if(fp == NULL){
		return 0;
	}

	fscanf(fp,"%d\n",&numStudent);
	for(i=0;i<numStudent;i++){
		stuRecords[i] = (Student*)malloc(sizeof(Student));
		fscanf(fp,"%[^,],%d\n",stuRecords[i]->name,&(stuRecords[i]->enterTime));
		//printf("\nThis is the name: %s the number: %d\n", stuRecords[i]->name,stuRecords[i]->enterTime);
	}
	fscanf(fp,"%s\n",&(currTutor->name));		// may have to use fgets then sscanf if not reading correctly  //This whole function may be wrong, I think
	//printf("\nThis is the tutor name %s\n",currTutor->name);
	fclose(fp);

	return numStudent;					// I am parsing the read info in wrong.
}

/*2*/void studentearlierQueue(Student* currStudent,Tutor* currTutor,QUEUE* studentLine,STACK* lineInfo)
{
	int count;
	Stats* queueData;

	queueData = (Stats*)malloc(sizeof(Stats));

	if(currTutor->studentHelped != NULL){ //Tutor is busy, student goes to queue
		currStudent->updateTime = currStudent->enterTime;
		queueData->qTime = currStudent->updateTime;
		enqueue(studentLine,((void*)currStudent));
		count = queueCount(studentLine);
		queueData->qLength = count;
		pushStack(lineInfo, ((void*)queueData)); //not sure about this;
		printf("Student %s is in line at time %d\n",currStudent->name,currStudent->enterTime);
	}
	else if(currTutor->studentHelped == NULL){ //Tutor is free
		currTutor->studentHelped = currStudent; //Assigns tutor pointer to Student
		currTutor->doneTime = (currStudent->enterTime) + 30; //Updates Tutor time when he finishes with student
		currStudent->updateTime = currStudent->enterTime; //Time student works with tutor
		printf("Student %s works with %s at time %d\n",currStudent->name,currTutor->name,currStudent->enterTime);
	}

}

/*3*/int tutorDoneStudent(Student* currStudent,Tutor* currTutor,QUEUE* studentLine,STACK* lineInfo)
{
	int count;
	Student* workStudent;

	workStudent = currTutor->studentHelped;
	printf("Student %s is done at time %d, wait time: %d\n",(workStudent->name),(currTutor->doneTime),
		(workStudent->updateTime - workStudent->enterTime));

	count = queueCount(studentLine);
	if(count != 0){//Queue is full
		dequeue(studentLine,((void**)(&workStudent)));	
		workStudent->updateTime = currTutor->doneTime; //When student begins working with tutor
		printf("Student %s works with %s at time %d\n",workStudent->name,currTutor->name,workStudent->updateTime);
		currTutor->doneTime = workStudent->updateTime + 30; //Tutor time is incremented to new finish time
		currTutor->studentHelped = workStudent;
		return 0;
	}
	else if(count == 0){//empty queue
		currTutor->studentHelped = NULL;
		studentearlierQueue(currStudent,currTutor,studentLine,lineInfo);
		printf("Student %s is done at time %d, wait time: %d\n",(currStudent->name),(currTutor->doneTime),
		(currStudent->updateTime - currStudent->enterTime));
	}
	return 1;

}

/*4*/void printlineStats(STACK* lineInfo)
{
	Stats* printData;
	int count = 0;

	while(count!=1){
		count = emptyStack(lineInfo);
		printData = (Stats*)popStack(lineInfo);
		printf("Queue Length = %d at time %d\n",printData->qLength,printData->qTime);
		free(printData);
	}
}