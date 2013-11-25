



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "llist.h"

typedef struct hashTable{
	char*word;
	int elemStatus;   //filled = 1
	LIST*collision;
}hashTable;

typedef struct linkedData{
	char*linkWord;
}linkedData;

#define MAX 25000

/*1*/void initHashArray(hashTable arrayHash[]);   //NOT SURE IF I SHOULD INITIALIZE ALL VARIABLES IN STRUCT ESPECIALLY elemStatus TO 0
/*2*/void storeFile(hashTable arrayHash[],linkedData linkArray[]);
/*3*/unsigned hash_Function(void*key,int strLength);
/*4*/int compareWord(void* inHashWord1, void* inHashWord2);
/*5*/void calcPrintData(hashTable arrayHash[]);
/*6*/void userInteraction(hashTable arrayHash[]); //Not doing yet, first printData correctly
/*7*/void freeData(hashTable arrayHash[],linkedData linkArray[]);

int main(void)
{
	hashTable arrayHash[MAX];
	linkedData linkArray[MAX];

	initHashArray(arrayHash);
	storeFile(arrayHash,linkArray);
	freeData(arrayHash,linkArray);

	return 0;
}


/*1*/void initHashArray(hashTable arrayHash[])
{
	int i;

	for(i=0;i<MAX;i++){
		arrayHash[i].word = NULL;
		arrayHash[i].elemStatus = 0;
		arrayHash[i].collision = NULL;
	}
}

/*2*/void storeFile(hashTable arrayHash[],linkedData linkArray[])
{
	FILE*fp;
	char tempStr[50];
	unsigned index,strLength, i;
	int linkIndex = 0;


	///*Testing*/FILE*Output;
	///*Testing*/Output = fopen("dictionaryoutput.txt","a");
	
	fp = fopen("dictionaryWords.txt","r");
	if(fp == NULL){
		printf("Error, FILE Was not read properly\n");
		exit(EXIT_FAILURE);
	}
	//need to fscanf until EOF maybe use fgets instead
	while((fgets(tempStr,50,fp)) != NULL){
	//fscanf(fp,"%s\n",tempStr);  NEED TO <EXCLUDE> APOSTROPHES IN SCAN LATER
		strLength = strlen(tempStr);
		if(tempStr[strLength-1] == '\n')
			tempStr[strLength - 1] = '\0';
		for(i=0;i<strLength;i++){ //Makes it all lowercase
			tempStr[i] = tolower(tempStr[i]);
		}

		///*Testing*/fprintf(Output,tempStr);
		///*Testing*/fprintf(Output,"\n");

		index = hash_Function((void*)tempStr,strLength);
		if(arrayHash[index].elemStatus == 1){
			linkArray[linkIndex].linkWord = (char*)malloc(strLength+1);
			strcpy(linkArray[linkIndex].linkWord,tempStr);
			if(arrayHash[index].collision == NULL){
				arrayHash[index].collision = createList(compareWord);
			}
			addNode(arrayHash[index].collision,(void*)linkArray[linkIndex].linkWord); //Nothing is in word right now //Need to sort hits alphabetically while adding
			linkIndex++;
		} 
		else if(arrayHash[index].elemStatus == 0){
			arrayHash[index].word = (char*)malloc(strLength+1);
			strcpy(arrayHash[index].word,tempStr);
			arrayHash[index].elemStatus = 1;
		}
	}
	calcPrintData(arrayHash);

	///*Testing*/fclose(Output);

	fclose(fp);
}

/*3*/unsigned hash_Function(void*key,int strLength)   //unsigned means 0 to 255
{
	unsigned char* temp;
	unsigned numberKey = 0;
	int i;

	//randomNumber = (unsigned)rand()/RAND_MAX * (50-1)+1;
	temp = (unsigned char*)key;
	for(i=0;i<strLength;i++){
		numberKey += temp[i];
	}
	
	return numberKey;
}

/*4*/int compareWord(void* inHashWord1, void* inHashWord2)
{
	char*word1;
	char*word2;
	int result;

	word1 = ((hashTable*)inHashWord1)->word;
	word2 = ((hashTable*)inHashWord2)->word;
	if (word1 < word2)
      result = -1;
	else if (word1 > word2)
      result = 1;
	else
      result = 0;

	return result;
}

/*5*/void calcPrintData(hashTable arrayHash[])  //ASK CLARE IF WE NEED TO PRINT THE SAME ORDER AS SHE HAS IN THE LAB INSTRUCTIONS
{	
	char*tempWord;
	double avgLinkedList;
	int linkedListLocation[MAX];  //NEED TO FIND A WAY TO MAKE THIS ARRAY SMALLER OR DYNAMIC
	int longestLengthListLocation[MAX];
	int longestLengthLinkedList, linkedCount, tempIndex, i;
	int totalPrime = 0;
	int linkedIndex = 0;
	int longestLinkIndex = 0;
	int linkedWordsAdd = 0;
	int linkedListLengthTotal = 0;
	int from = 0;
	
	for(i=0;i<MAX;i++){
		if(arrayHash[i].elemStatus == 1){ //array is full
			if(arrayHash[i].collision != NULL){ //may have to do an if else statement
				linkedCount = listCount(arrayHash[i].collision);
				linkedWordsAdd += linkedCount+1;   //When not adding one to linkedCount, the count is 988 (wrong)
				linkedListLocation[linkedIndex] = i; //When doing linkedCount+1, the count is 1229 which is right
				linkedIndex++;
			}
			else if(arrayHash[i].collision == NULL){
				totalPrime++;
			}
		}
	}
	for(i=0;i<linkedIndex;i++){ //finding total of linked list lengths for average computation
		linkedListLengthTotal += listCount(arrayHash[(linkedListLocation[i])].collision);
	}
	avgLinkedList = (double)linkedListLengthTotal/linkedIndex;  //may need parantheses around the two terms

	longestLengthLinkedList = (listCount(arrayHash[(linkedListLocation[0])].collision)); //finding longest length linked list
	for(i=0;i<linkedIndex;i++){ //finding longest length linked list
		if((listCount(arrayHash[(linkedListLocation[i])].collision))>longestLengthLinkedList){
			longestLengthLinkedList = (listCount(arrayHash[(linkedListLocation[i])].collision));
		}
	}
	for(i=0;i<linkedIndex;i++){ //Finding locations of longest Linked Lists
		if(longestLengthLinkedList == (listCount(arrayHash[(linkedListLocation[i])].collision))){
			longestLengthListLocation[longestLinkIndex] = linkedListLocation[i];
			longestLinkIndex++;
		}
	}	
	for(i=0;i<linkedIndex;i++){ // print index with the linked list length at the index
		printf("index %d list length %d\n",linkedListLocation[i],
			(listCount(arrayHash[(linkedListLocation[i])].collision)));
	}
	printf("\nTotal entries: %d\n",(totalPrime + linkedWordsAdd));
	printf("Entries in primary area: %d\n", totalPrime);
	printf("Number of linked lists: %d\n",linkedIndex);
	printf("Average list length %4.2f\n",avgLinkedList);
	printf("Longest list length: %d\nat index:",longestLengthLinkedList);
	for(i=0;i<longestLinkIndex;i++){
		tempIndex = longestLengthListLocation[i];
		printf("\n%d:",tempIndex);
		while((traverse(arrayHash[tempIndex].collision,from,(void**)&tempWord)) != 0){ //Not sure if this works (the void**&tempWord part)
			printf(" %s",tempWord); //Not sure if it should be *tempWord or tempWord
			from++;
		}
	}
	userInteraction(arrayHash);
}

/*6*/void userInteraction(hashTable arrayHash[])
{
	FILE*fp;
	char filename[30];
	char tempStr[100];
	char*linkedWord;
	int strLength;
	int strIndex, strCompare, equalStatus,from,i,j;
	int inQuit = 0;
	int notFound = 0;

	printf("\n\nfilename ('quit' to quit):"); //Only doing one loop for now, need to do while loop after program works
	fgets(filename,30,stdin);  //Not sure if this works
	strLength = strlen(filename);
	if(filename[strLength-1] == '\n')
			filename[strLength - 1] = '\0';
	if(strcmp(filename,"quit")==0){
		exit(0);
	}
	fp = fopen(filename,"r");
	while(fp == NULL){
		printf("Please enter a correct filename:");
		fgets(filename,30,stdin);  //Not sure if this works, may not to fflush buffer
		if(strcmp(filename,"quit")==0){
			exit(0);
		}
		fp = fopen(filename,"r");
	}
	printf("Words not found:\n");
	while(fscanf(fp,"%s",tempStr)!= EOF) //This does one word at a time
	{
		strLength = strlen(tempStr);
		if(tempStr[strLength-1] == '\n')
			tempStr[strLength - 1] = '\0';
		for(i=0;i<strLength;i++){
			tempStr[i] = tolower(tempStr[i]);
		}
		equalStatus = 0;
		for(i=0;i<MAX;i++){
			if(arrayHash[i].word != NULL){
				strCompare = strcmp(arrayHash[i].word,tempStr);
				if(strCompare == 0){
					equalStatus = 1;
				}
				if(arrayHash[i].collision != NULL){
					strCompare = strcmp(arrayHash[i].word,tempStr);
					if(strCompare == 0){
						equalStatus = 1;
					}
					from = 0;
					while((traverse(arrayHash[i].collision,from,(void**)&linkedWord)) != 0){ //Not sure if this works (the void**&tempWord part)
						strCompare = strcmp(linkedWord,tempStr);
						if(strCompare == 0){
							equalStatus = 1;
						}
						from++;
					}
				}
			}
		}
		if(equalStatus == 0){
		printf("%s\n",tempStr);
		notFound ++;
		}
	}
	printf("Total number of words not found in dictionary: %d\n",notFound);
	fclose(fp);
}

/*7*/void freeData(hashTable arrayHash[],linkedData linkArray[]) //NOT SURE IF THIS WORKS YET
{
	int i;
	int from;
	char*linkedWord;

	for(i=0;i<MAX;i++){
		free(arrayHash[i].word);
		free(linkArray[i].linkWord);
	}
	for(i=0;i<MAX;i++){
		if(arrayHash[i].collision != NULL){
			from = 0;
			while((traverse(arrayHash[i].collision,from,(void**)&linkedWord)) != 0){
				free(linkedWord);
				from++;
			}
			destroyList(arrayHash[i].collision);
		}
	}
}