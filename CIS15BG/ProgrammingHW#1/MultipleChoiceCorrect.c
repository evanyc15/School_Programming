/*
Program Name: Evan Chen
Date: 10/05/12
OS: Microsoft Windows 7 Enterprise Version 6.1.7600 Build 7600 x64-based PC
Description: This program reads a file that contains answers to a
multiple choice test,student IDs and their answers to the test.
The program corrects each student's test and then prints the
student ID and their test score. Following this, the program also
prints how many students answered each test question correctly.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMS 100;

//Prototype Declarations
int readElems(FILE*infile, int answerArray[]);
void readArray(int i, int answerArray[],FILE*infile);
void processStudentData(FILE*infile,FILE*outfile, int studentID[],int stuAnswerArray[],
                        int answerArray[], int frequencyArray[],int numElems);
int correctTest(int answerArray[], int stuAnswerArray[], int frequencyArray[],int numElems);
void questionsCorrect(FILE*outfile,int numElems, int answerArray[],int frequencyArray[]);

int main(){

//Statements
int i;
int answerArray[i];
int frequencyArray[i];
int stuAnswerArray[i];
int studentID[i];
int numElems;
FILE*infile;
FILE*outfile;

//Opens the input and output files
    infile=fopen("C:/Users/evanc/Desktop/ProgrammingHW#1/test1.txt","r");
    outfile=fopen("C:/Users/evanc/Desktop/ProgrammingHW#1/testresult.txt","w");
//Checks if file opens
    if(infile==0 || outfile==0){
    printf("Can't find file.\n");
    exit(1);
    }
    numElems=readElems(infile, answerArray);
    processStudentData(infile,outfile,studentID,stuAnswerArray,answerArray,frequencyArray,numElems);
    questionsCorrect(outfile,numElems,answerArray,frequencyArray);

   return 0;
}

int readElems(FILE*infile,int answerArray[])
{
    int i;
    fscanf(infile,"%d", &i);
    if(i>=0 && i<=100)
    {
    readArray(i,answerArray,infile);
    }
    return i;
}

void readArray(int numElems, int answerArray[],FILE*infile)
{
    int j;
    for(j=0;j<numElems;j++){
    fscanf(infile,"%d",answerArray[j]);
    }
}

void processStudentData(FILE*infile, FILE*outfile,int studentID[],
                        int stuAnswerArray[], int answerArray[],
                        int frequencyArray[],int numElems)
{
    int j;
    int k;
    fprintf(outfile,"Student ID\tTest Score\n");
    while(fscanf(infile,"%d",studentID[j]) !=EOF)
    {
        int studentscore=0;
        for(k=0;k<numElems;k++){
        fscanf(infile,"%d", stuAnswerArray[k]);
        }
    studentscore = correctTest(answerArray,stuAnswerArray,frequencyArray,numElems);
    fprintf(outfile,"%d %d", studentID[j],stuAnswerArray[k]);
    j++;
    }
}

int correctTest(int answerArray[], int stuAnswerArray[], int frequencyArray[],int numElems){
{
    int studentscore=0;
    int i;
    for(i=0;i<numElems;i++){
    if(stuAnswerArray[i]==answerArray[i])
    studentscore++;
    frequencyArray[i]+=1;
    }
    return studentscore;
    }

}

void questionsCorrect(FILE*outfile,int numElems, int answerArray[],int frequencyArray[]){

int i;
int problemNums=1;

fprintf(outfile,"Problem #:\t");
for(i=0;i<numElems;i++){
fprintf(outfile,"%d\t",problemNums);
problemNums++;
}
fprintf(outfile,"Answer Key:\t");
for(i=0;i<numElems;i++){
fprintf(outfile,"%d\t",answerArray[i]);
}
fprintf(outfile,"Frequency:\t");
for(i=0;i<numElems;i++){
fprintf(outfile,"%d\t",frequencyArray[i]);
}
}





