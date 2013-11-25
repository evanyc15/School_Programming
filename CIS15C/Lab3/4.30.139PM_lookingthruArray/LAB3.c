/*********************************************************
LAB 3: Dictionary
Description: This reads a list of dictionary words from a text file
and then stores it into a hash array. If collisions occur, the words
are stored in linked lists. The user then enters text files to see 
what and how many words are in the text file and not in the dictionary
By: Evan Chen
April 27, 2013 - April 30, 2013
***********************************************************/

//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "llist.h"

//Global Declarations
#define MAX 5000

//Structures
typedef struct hashTable{
	char*word;
	int elemStatus;   //filled = 1
	LIST*collision;
}hashTable;

typedef struct linkedData{ //This structure is used to store the words for the linked lists
	char*linkWord;
}linkedData;

//Function Prototypes
/*1*/void initHashArray(hashTable arrayHash[]); 
/*2*/void storeFile(hashTable arrayHash[],linkedData linkArray[]);
/*3*/unsigned hash_Function(void*key,int strLength);
/*4*/int compareWord(void* inHashWord1, void* inHashWord2);
/*5*/void calcPrintData(hashTable arrayHash[]);
/*6*/void userInteraction(hashTable arrayHash[]);
/*7*/void freeData(hashTable arrayHash[]);

int main(void)
{
	hashTable arrayHash[MAX];
	linkedData linkArray[MAX];

	initHashArray(arrayHash);
	storeFile(arrayHash,linkArray);
	freeData(arrayHash);

	return 0;
}

/*initHashArray: initializes all the arrayHash char pointers
to NULL, the elemStatus int to 0, and the linked list pointers 
to NULL
Input: arrayHash(array of hashTable struct)
Return: Nothing
/*1*/void initHashArray(hashTable arrayHash[])
{
	int i;

	for(i=0;i<MAX;i++){
		arrayHash[i].word = NULL;
		arrayHash[i].elemStatus = 0;
		arrayHash[i].collision = NULL;
	}
}//end initHashArray

/*storeFile: reads dictionary words from a file and uses a hash function
to store them into a hash array of hashTable structs. If collision occurs
then a linked list is created if not already created and then the word
is added to a new node.
Input: arrayHash(array of hashTable struct), linkArray(array of linkedData struct)
Return: Nothing
/*2*/void storeFile(hashTable arrayHash[],linkedData linkArray[])
{
	FILE*fp;
	char tempStr[50];
	unsigned index;
	int strLength,current,next,i;
	int linkIndex = 0;

	fp = fopen("dictionaryWords.txt","r");
	if(fp == NULL){
		printf("Error, FILE Was not read properly\n");
		exit(EXIT_FAILURE);
	}
	while(fscanf(fp,"%s",tempStr) != EOF){
		strLength = strlen(tempStr);
		current = 0;
		next = 0;
		if(tempStr[strLength-1] == '\n') //Inserts null character just in case
			tempStr[strLength - 1] = '\0';
		while(tempStr[current] != '\0'){ //Takes out special characters
			if(isalpha(tempStr[current])){
				tempStr[next] = tempStr[current];
				next++;
			}
			current++;
		}
		tempStr[next] = '\0';
		strLength = strlen(tempStr);
		for(i=0;i<strLength;i++){ //Makes it all lowercase
			tempStr[i] = tolower(tempStr[i]);
		}
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
	fclose(fp);
}//end storeFile

/*hash_Function: This is the hash function for the hash array that 
uses the dictionary word as the key to create a special index
Input: key(void*), strLength(int)
Return: temp(unsigned)
Hashing Algorithms used: Adding, Rotation Method, Modulo-Division
Reason for Algorithm: Using various Hashing algorithms has helped 
/*3*/unsigned hash_Function(void*key,int strLength)   //unsigned means 0 to 255
{
	unsigned char* tempKey;
	unsigned temp = 0;
	int i;

	tempKey = (unsigned char*)key;
	for(i=0;i<strLength;i++){
		temp += tempKey[i]; 
		temp += (temp << 9);
		temp ^= (temp >> 7);
	}
	temp += (temp << 8);
	temp ^= (temp >> 6);
	temp += (temp << 7);
	temp = (temp % 10000)/2;

	return temp;
}//end hash_Function

/*compareWord: This function will be used by the createList
function. The function tells createList how to sort the
data being inserted. The function will sort the dictionary
words by alphabetical order.
Input: inHashWord1(void*), inHashWord2(void*)
Return: result(int)
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
}//end compareWord

/*calcPrintData: This function will print out
all the stats which include total number of words,
all indexes that have a linked list and the length
of the list, total number of words in prime area,
total number of linked lists, average length of
linked lists, longest length of linked lists, and
print index and words in longest length lists
Input: arrayHash(array of hashTable structs)
Return: Nothing
/*5*/void calcPrintData(hashTable arrayHash[]) 
{	
	char*tempWord;
	double avgLinkedList;
	int linkedCount,from,i;
	int totalPrime = 0;
	int linkedListCount = 0;
	int longestLinkIndex = 0;
	int linkedListLengthTotal = 0;
	int longestLengthLinkedList = 0;
	
	for(i=0;i<MAX;i++){
		if(arrayHash[i].elemStatus == 1){ //array is full
			if(arrayHash[i].collision != NULL){
				linkedCount = listCount(arrayHash[i].collision);
				linkedListLengthTotal += linkedCount;
				totalPrime++;
				linkedListCount++;
			}
			else if(arrayHash[i].collision == NULL){
				totalPrime++;
			}
		}
	}
	avgLinkedList = (double)linkedListLengthTotal/linkedListCount; 
	for(i=0;i<MAX;i++){ //finding longest length linked list
		if(arrayHash[i].collision != NULL){
			linkedCount = listCount(arrayHash[i].collision);
			if(linkedCount >= longestLengthLinkedList)
				longestLengthLinkedList = linkedCount;
		}
	}
	for(i=0;i<MAX;i++){ // print index with the linked list length at the index
		if(arrayHash[i].collision != NULL){
			linkedCount = listCount(arrayHash[i].collision);
			printf("index %d list length %d\n",i,linkedCount);
		}
	}
	printf("\nTotal entries: %d\n",(totalPrime + linkedListLengthTotal));
	printf("Entries in primary area: %d\n", totalPrime);
	printf("Number of linked lists: %d\n",linkedListCount);
	printf("Average list length %4.2f\n",avgLinkedList);
	printf("Longest list length: %d\nat index:",longestLengthLinkedList);
	for(i=0;i<MAX;i++){
		if(arrayHash[i].collision != NULL){
			linkedCount = listCount(arrayHash[i].collision);
			if(longestLengthLinkedList == linkedCount){
				printf("\n%d:",i);
				from = 0;
				while((traverse(arrayHash[i].collision,from,(void**)&tempWord)) != 0){ 
					printf(" %s",tempWord);
					from++;
				}
			}
		}
	}
	userInteraction(arrayHash);
}//end calcPrintData

/*userInteraction: This function involves the user.
It will ask the user for a file and then read it word
by word. For each word, it will search the hash array
dictionary and print the words if it is not in the 
dictionary. It will then print the total words missing
from dictionary.
Input: arrayHash(array of hashTable structs)
Return: void
/*6*/void userInteraction(hashTable arrayHash[])
{
	FILE*fp;
	char filename[30];
	char tempStr[100];
	char*linkedWord;
	int strLength;
	int strCompare,equalStatus,from,i;
	int inQuit = 0;
	int notFound = 0;

	printf("\n\nfilename ('quit' to quit):");
	fscanf(stdin,"%s",filename); 
	strLength = strlen(filename);
	if(filename[strLength-1] == '\n')
		filename[strLength - 1] = '\0';
	if(strcmp(filename,"quit")==0){
		exit(0);
	}
	fp = fopen(filename,"r");
	while(fp == NULL){
		printf("Please enter a correct filename:");
		fscanf(stdin,"%s",filename); 
		strLength = strlen(filename);
		if(filename[strLength-1] == '\n')
			filename[strLength - 1] = '\0';
		if(strcmp(filename,"quit")==0){
			exit(0);
		}
		fp = fopen(filename,"r");
	}
	printf("Words not found:\n");
	while(fscanf(fp,"%s",tempStr)!= EOF) 
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
					while((traverse(arrayHash[i].collision,from,(void**)&linkedWord)) != 0){
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
}//end userInteraction

/*freeData: This function will free all the allocated
memory and destroy the linked List
Input: arrayHash(array of hashTable structs)
Return: Nothing
/*7*/void freeData(hashTable arrayHash[])
{
	int i;

	for(i=0;i<MAX;i++){
		if(arrayHash[i].elemStatus == 1){
			if(arrayHash[i].collision != NULL){
				destroyList(arrayHash[i].collision);
			}
			free(arrayHash[i].word);
		}
	}
}//end freeData