//Evan Chen
//Lab Assignment #1

//Header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Global Declarations
typedef struct{
    char *name;
    int score;
}Student;

//Function Prototype Declaration
/*1*/void sortArray(Student stuArray[],int numScores);
/*2*/int calcMedian(Student stuArray[],int numScores);
/*3*/float calcMean(int scoreTotal,int numScores);
/*4*/void printData(Student stuArray[], int scoreTotal,int numScores,
                    float mean, int median);
/*5*/int calcMode(Student stuArray[],int numScores);
/*6*/void printHistogram(Student stuArray[],int numScores);
/*7*/void freeMem(Student stuArray[],int numScores);

int main(void)
{
//Local Declarations
    Student stuArray[50];
    FILE*fp;
    char tempStr[100];
    char filename[100];
    char tempS[100];
    int strLength,i,median,mode;
    int numScores = 0;
    int scoreTotal = 0;
    int index = 0;
    int openTest = 1;
    float mean;

    while(openTest == 1){
        printf("Enter filename: ");
        scanf("%s",&filename);
        fp = fopen(filename,"r");
        if(fp!=NULL){
            openTest = 0;
        }
    }

    while(((fgets(tempStr,100,fp))!=NULL)&&numScores<50){
    sscanf(tempStr,"%[^,], %d",&tempS,&(stuArray[index].score));
    strLength = (strlen(tempS))+1;
    stuArray[index].name = malloc(strLength*sizeof(Student));
    if((stuArray[index].name)==NULL){
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }
    strcpy((stuArray[index].name),tempS);
    scoreTotal += (stuArray[index].score);
    numScores++;
    index++;
    }
    fclose(fp);

    if(numScores < 50){
        for(i=numScores+1;i<50;i++){
            stuArray[i].name = NULL;
            stuArray[i].score = 0;
        }
    }
    if(numScores>=50){
        printf("The file contains more than 50 name/scores, only 50 of them have been read\n");
    }

    sortArray(stuArray, numScores);
    median = calcMedian(stuArray,numScores);
    mean = calcMean(scoreTotal,numScores);
    printData(stuArray,scoreTotal,numScores,mean,median);
    mode = calcMode(stuArray,numScores);
    printHistogram(stuArray,numScores);

    if(mode == 0){
        printf("\nThere is no mode\n");
    }
    if(mode!=0){
        printf("\nMode = %d\n",mode);
    }

    freeMem(stuArray,numScores);
    return 0;
}//end main

/*sortArray: This function will sort the array of Student structs
by ascending score
Input: array of Student structs, numScores(int)
Return: Nothing*/
/*1*/void sortArray(Student stuArray[],int numScores)
{
    int j,k;
    Student temp;

    for(j=0;j<numScores-1;j++){ //bubble sort
        for(k=0;k<numScores-j-1;k++){
        if(stuArray[k].score > stuArray[k+1].score){
        temp = stuArray[k];
        stuArray[k] = stuArray[k+1];
        stuArray[k+1] = temp;
        }
        }
    }
}//end sortArray

/*calcMedian: This function will find out the median of the student scores.
If the number of scores is even then the median will be calculated by
averaging the middle two numbers.
Input: array of Student structs, numScores(int)
Return: median(int)
/*2*/int calcMedian(Student stuArray[],int numScores)
{
    int median;

    if(numScores%2 == 0){ //Checks if there are even numScores
        median = (stuArray[numScores/2].score + stuArray[numScores/2 - 1].score)/ 2;
    }
    else //Gives the median within odd numScores
        median = stuArray[numScores/2].score;

    return median;
}//end calcMedian

/*calMean: This function will find out the mean of the student scores
by adding the scores together and dividing by the total number of scores.
Input: scoreTotal(int),numScores(int)
Return: mean(float)
/*3*/float calcMean(int scoreTotal,int numScores)
{
    return ((float)scoreTotal/numScores);
}//end calcMean

/*printData: This function prints out the number of data records read in,
the mean, the Name and respective score, sorted by the scores, and then
the median.
Input: array of Student structs, scoreTotal(int),numScores(int),mean(float),median(int)
Return: Nothing*/
/*4*/void printData(Student stuArray[], int scoreTotal,int numScores,
                    float mean, int median)
{
    int i;

    printf("Read in %d data records\n",numScores);
    printf("\nMean = %d / %d = %5.2f\n",scoreTotal,numScores,mean);
    printf("\nRecords sorted by scores:\n");

    for(i=0;i<numScores;i++){
    printf("%-20s  %d\n",(stuArray[i].name),(stuArray[i].score));
    }
    printf("\nMedian = %d\n",median);
}//end printData

/*calcMode: This is the function that calculates the mode of the scores
Input: array of Student struct, numScores(int)
Return: mode(int)*/
/*5*/int calcMode(Student stuArray[],int numScores)
{
    int i;
    int modeCounter = 0;
    int currentNum = 0;
    int maxNum = 0;
    int mode = 0;
    int noMode = 0;

    for(i=0;i<numScores;i++){
        if(currentNum!=(stuArray[i].score)){   //assigns the first num to compare
            currentNum = (stuArray[i].score);
            modeCounter = 1;
        }
        else
            modeCounter++;  //if currentNum is same as next then increment
        if(modeCounter == maxNum){
            noMode = 0;
        }
        if(modeCounter > maxNum){
            maxNum = modeCounter;   //tracks for the most repeated number and assigns to maxNum
            noMode = modeCounter;
            mode = currentNum;
        }
    }
    if(noMode == 0){
        return 0;
    }
	else
        return mode;
}//end calcMode

/*printHistogram: This function prints out the histogram to show the frequency of each score.
Input: array of Student structs, numScores(int)
Return: Nothing
/*6*/void printHistogram(Student stuArray[],int numScores)
{
    int i,j;
    int currentNum = 0;

    printf("\n\nHistogram:\n");
    for(i=0;i<numScores;i++){
        currentNum = (stuArray[i].score);  //assigns the first num to compare
        printf(" %d: ",currentNum);        //prints out first number
        for(j=0;j<numScores;j++){
            if(currentNum == (stuArray[j].score)){  //if same as next number then prints x
            printf("x");
            i++; //increments to prevent the next same number from printing again
            }
        }
        i--; //Previous increment adds too much on the last loop
        printf("\n");
    }
}//end printHistogram

/*freeMem: This function will free the dynamically allocated memory of the
array of Student struct names.
Input: array of Student struct, numScores(int)
Return: Nothing*/
/*7*/void freeMem(Student stuArray[],int numScores)
{
    int i;
    for(i=0;i<numScores;i++){
        free(stuArray[i].name);
    }
}//end freeMem
