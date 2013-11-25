



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

typedef struct hashTable{
	char*word;
	int elemStatus;   //filled = 1
	LIST*collision;
}hashTable;


#define MAX 75000

/*1*/void initHashArray(hashTable arrayHash[]);   //NOT SURE IF I SHOULD INITIALIZE ALL VARIABLES IN STRUCT ESPECIALLY elemStatus TO 0
/*2*/void storeFile(hashTable arrayHash[]);
/*3*/unsigned hash_Function(void*key,int strLength);
/*4*/int compareWord(void* inHashWord1, void* inHashWord2);
/*5*/void calcPrintData(hashTable arrayHash[]);
/*6*/void userInteraction(); //Not doing yet, first printData correctly

int main(void)
{
	hashTable arrayHash[MAX];
	initHashArray(arrayHash);
	storeFile(arrayHash);

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

/*2*/void storeFile(hashTable arrayHash[])
{
	FILE*fp;
	char tempStr[50];
	int index,strLength;
	
	fp = fopen("dictionaryWords.txt","r");
	if(fp == NULL){
		printf("Error, FILE Was not read properly\n");
		exit(EXIT_FAILURE);
	}
	//need to fscanf until EOF maybe use fgets instead
	while((fgets(tempStr,100,fp)) != NULL){

	//fscanf(fp,"%s\n",tempStr);  NEED TO <EXCLUDE> APOSTROPHES IN SCAN LATER

		strLength = strlen(tempStr);
		index = (int)hash_Function((void*)tempStr,strLength);
		if(arrayHash[index].elemStatus != 1){
			arrayHash[index].word = (char*)malloc(strLength+1);
			strcpy(arrayHash[index].word,tempStr);
			arrayHash[index].elemStatus = 1;
		}
		if(arrayHash[index].elemStatus == 1){
			if(arrayHash[index].collision == NULL){
				arrayHash[index].collision = createList(compareWord);
				///*Testing*/ printf("arrayHash collision is NULL\n");
			}
			addNode(arrayHash[index].collision,(void*)arrayHash[index].word); //Need to sort hits alphabetically while adding
		}
	}
	calcPrintData(arrayHash);
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
	double avgLinkedList;
	char*tempWord;
	int linkedListLocation[9000];  //NEED TO FIND A WAY TO MAKE THIS ARRAY SMALLER OR DYNAMIC
	int*longestLengthListLocation;
	int longestLengthLinkedList, linkedCount, i;
	int totalPrimeWords = 0;
	int linkedIndex = 0;
	int longestLinkIndex = 0;
	int totalWords = 0;
	int linkedListLengthTotal = 0;
	int from = 0;

	for(i=0;i<MAX;i++){
		if(arrayHash[i].elemStatus == 1){ //array is full
			if(arrayHash[i].collision == NULL){
				totalWords++;
				totalPrimeWords++;
			} 
			if(arrayHash[i].collision != NULL){ //may have to do an if else statement
				linkedCount = listCount(arrayHash[i].collision);
				totalWords += linkedCount;
				linkedListLocation[linkedIndex] = i;
				linkedIndex++;
			}
		}
	}
	for(i=0;i<linkedIndex;i++){ //finding total of linked list lengths for average computation
		linkedListLengthTotal += listCount(arrayHash[(linkedListLocation[i])].collision);
	}
	avgLinkedList = (double)linkedListLengthTotal/linkedIndex;  //may need parantheses around the two terms
	for(i=0;i<linkedIndex-1;i++){ //finding longest length linked list
		if((listCount(arrayHash[(linkedListLocation[i])].collision))
			<=(listCount(arrayHash[(linkedListLocation[i+1])].collision))){
				longestLengthLinkedList = (listCount(arrayHash[(linkedListLocation[i+1])].collision));
		}
	}
	longestLengthListLocation =(int*)malloc(linkedIndex);
	for(i=0;i<linkedIndex;i++){ //Finding locations of longest Linked Lists
		if(longestLengthLinkedList == (listCount(arrayHash[(linkedListLocation[i])].collision))){
			longestLengthListLocation[longestLinkIndex] = linkedListLocation[i];
			longestLinkIndex++;
		}
	}	
	/*for(i=0;i<linkedIndex;i++){ // print index with the linked list length at the index
		printf("index %d list length %d\n",linkedListLocation[i],
			(listCount(arrayHash[(linkedListLocation[i])].collision)));
	}*/
	printf("Total entries: %d\n",totalWords);
	printf("Entries in primary area: %d\n", totalPrimeWords);
	printf("Number of linked lists: %d\n",linkedIndex);
	printf("Average list length %f",avgLinkedList);
	printf("Longest list length: %d\n at index: ",longestLengthLinkedList);
	for(i=0;i<longestLinkIndex++;i++){
		while(traverse(arrayHash[i].collision,from,(void**)&tempWord)){ //Not sure if this works (the void**&tempWord part)
			printf(" %s",*tempWord); //Not sure if it should be *tempWord or tempWord
			from++;
		}
	}
}

/*6*/void userInteraction()
{


}