/*********************************************************
LAB 2: Student Tutoring Schedule and Hours
Description: The program uses one tutor to calculate what times he works with students
or students are queued if the tutor is busy.
This program involves queues and stacks.
By: Evan Chen
April 16, 2013 - April 22, 2013
***********************************************************/

//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

//Global Declarations
#define MAX 100
#define _CRT_SECURE_NO_WARNINGS 1 //Removes some warnings, take off when real testing

//Structures
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

//Function Prototypes
/*1*/int readTutorStuData(Student* stuRecords[],Tutor* currTutor);
/*2*/void studentearlierQueue(Student* currStudent,Tutor* currTutor,QUEUE* studentLine,STACK* lineInfo);
/*3*/int tutorDoneStudent(Student* currStudent,Tutor* currTutor,QUEUE* studentLine,STACK* lineInfo);
/*4*/void printlineStats(STACK* lineInfo);

int main(void)
{
	Student *stuRecords[MAX];
	Student* currStudent;
	Student* temp;
	Stats* queueData;
	Tutor* currTutor;
	QUEUE* studentLine;
	STACK* lineInfo;
	int numStudent, queueStatus;
	int index = 0;
	int studentProcessed = 1;

	studentLine = createQueue();  //Creates Queue
	lineInfo = createStack();	  //Creates Stack
	currTutor = (Tutor*)malloc(sizeof(Tutor));  //Allocate memory for Tutor
	queueData = (Stats*)malloc(sizeof(Stats)); //Allocate memory for Queue
	currTutor->studentHelped = NULL; //Initialize tutor pointer to NULL
	currTutor->doneTime = 999; //Initialize tutor time to a big number

	numStudent = readTutorStuData(stuRecords,currTutor);  //Reads data from textfile
	if(numStudent == 0){
		printf("File cannot open\n");
		return 0;
	}
	while(index<numStudent && (studentProcessed == 1)){ //Process the data
		currStudent = stuRecords[index];
		if((currStudent->enterTime)<(currTutor->doneTime)){ //If Student enter Time is less than Tutor's done Time
			studentearlierQueue(currStudent,currTutor,studentLine,lineInfo);
			index++;
		}
		else if((currTutor->doneTime)<=(currStudent->enterTime)){ //When tutor is helping no student
			temp = currTutor->studentHelped;
			printf("Student %s is done at time %d, wait time: %d\n",(temp->name),(currTutor->doneTime),(temp->updateTime - temp->enterTime));
			queueStatus = tutorDoneStudent(currStudent,currTutor,studentLine,lineInfo);
			studentProcessed == queueStatus;
			if(queueStatus == 1){
				if(index != numStudent){
					index++;
				}
			}
		}
	}
	queueStatus = emptyQueue(studentLine);
	while(queueStatus == 0){ //Check if queue is empty or not and processes it if it is full
		temp = currTutor->studentHelped;
		printf("Student %s is done at time %d, wait time: %d\n",(temp->name),(currTutor->doneTime),
		(temp->updateTime - temp->enterTime));
		tutorDoneStudent(currStudent,currTutor,studentLine,lineInfo);
		queueStatus = emptyQueue(studentLine);
	}
	printf("Student %s is done at time %d, wait time: %d\n",(currStudent->name),(currTutor->doneTime),(currStudent->updateTime - currStudent->enterTime));
	printf("Simulation done\n\n");
	printlineStats(lineInfo);

	destroyQueue(studentLine);
	destroyStack(lineInfo);
	free(currTutor);
	free(queueData); 
	return 0;
}//end main

/*readTutorStuData: Reads data in from a textfile that consists of how many students there are, the student's names,
their enter time, and then the tutor's name located at the end of file.
Input: stuRecords(array of pointers to Student struct), currTutor(pointer to Tutor struct)
Return: numStudent(int)
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
	}
	fscanf(fp,"%s\n",&(currTutor->name));	

	fclose(fp);
	return numStudent;					
}//end readTutorStuData

/*studentearlierQueue: This function is called if the current student's enter time is less than the tutor's done time
This function will then queue the student if the tutor is busy or help the student if the tutor is free. The function
also will save to the stack the queue length and time when there is a queue line.
Input: currStudent(pointer to Student struct), currTutor(pointer to Tutor struct), studentLine(pointer to QUEUE),
lineInfo(pointer to STACK)
Return: Nothing
/*2*/void studentearlierQueue(Student* currStudent,Tutor* currTutor,QUEUE* studentLine,STACK* lineInfo)
{
	int count;
	Stats* queueData;

	queueData = (Stats*)malloc(sizeof(Stats));

	if(currTutor->studentHelped != NULL){ //Tutor is busy, student goes to queue
		currStudent->updateTime = currStudent->enterTime;
		queueData->qTime = currStudent->updateTime;
		enqueue(studentLine,((void*)currStudent)); //Queue student
		count = queueCount(studentLine);
		queueData->qLength = count;
		pushStack(lineInfo, ((void*)queueData)); //Line info into STACK
		printf("Student %s is in line at time %d\n",currStudent->name,currStudent->enterTime);
	}
	else if(currTutor->studentHelped == NULL){ //Tutor is free
		currTutor->studentHelped = currStudent; //Assigns tutor pointer to Student
		currTutor->doneTime = (currStudent->enterTime) + 30; //Updates Tutor time when he finishes with student
		currStudent->updateTime = currStudent->enterTime; //Time student works with tutor
		printf("Student %s works with %s at time %d\n",currStudent->name,currTutor->name,currStudent->enterTime);
	}
}//end studentearlierQueue

/*tutorDoneStudent: This function is called if the tutor done time is less than the student's enter time. 
If there is a queue then the function will dequeue and assign the dequeued student to the tutor. The function
also will save to the stack the queue length and time when there is a queue line. If the queue is empty, the function
will assign the current Student to the tutor.
Input: currStudent(pointer to Student struct), currTutor(pointer to Tutor struct), studentLine(pointer to QUEUE),
lineInfo(pointer to STACK)
Return: queueStatus(int)
/*3*/int tutorDoneStudent(Student* currStudent,Tutor* currTutor,QUEUE* studentLine,STACK* lineInfo)
{
	int count;
	Student* workStudent;
	Stats* queueData2;
	
	queueData2 = (Stats*)malloc(sizeof(Stats));

	count = queueCount(studentLine);
	if(count != 0){ //Queue is full
		dequeue(studentLine,((void**)(&workStudent))); //Dequeue student and assign to void** Student
		workStudent->updateTime = currTutor->doneTime; //When student begins working with tutor
		printf("Student %s works with %s at time %d\n",workStudent->name,currTutor->name,workStudent->updateTime);
		currTutor->doneTime = workStudent->updateTime + 30;
		currTutor->studentHelped = workStudent;
		if((count-1) != 0){
			queueData2->qTime = workStudent->updateTime;
			queueData2->qLength = count;
			pushStack(lineInfo, ((void*)queueData2));
		}
		return 0;
	}
	else if(count == 0){ //Queue is empty
		currTutor->studentHelped = NULL;
		studentearlierQueue(currStudent,currTutor,studentLine,lineInfo);
	}
	
	return 1;
}//end tutorDoneStudent

/*printLineStats: This function will use the STACK to print the queue length and time when
the queue was full at certain times.
Input: lineInfo(pointer to STACK)
Return: Nothing
/*4*/void printlineStats(STACK* lineInfo)
{
	Stats* printData;
	int count = 0;

	while(count!=1){
		printData = (Stats*)popStack(lineInfo);
		printf("Queue Length = %d at time %d\n",printData->qLength,printData->qTime);
		count = emptyStack(lineInfo);
	}
}//end printLineStats