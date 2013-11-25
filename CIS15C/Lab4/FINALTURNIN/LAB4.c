/**************************************************************/
/*Lab 4: Read in contact information into a BST tree and allow*/
/*user to add, delete, or lookup and change information in the*/
/*BST tree													  */
/*By: Evan Chen												  */
/*April 11, 2013											  */
/**************************************************************/

//Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

//Global Declaration
#define MAX 100

//Structures
typedef struct contactData{
char name[80];   //This is the key
char phoneNum[80];   //This is the value
char webAddr[80];	// This is the value as well(optional)
}contactData;

//Function Prototypes
/*1*/void readFileBST(BST* contactBST);
/*2*/int compareWord(void* name1, void* name2);
/*3*/void printTree(void* dataInPtr);
/*4*/void addName(BST* contactBST);
/*5*/void deleteName(BST* contactBST);
/*6*/void lookupName(BST* contactBST);

int main(void)
{
	BST* contactBST; 
	char userInput;
	int inputStatus;
	int quitStatus = 0;

	contactBST = createBST(compareWord);
	if(contactBST == NULL){
		printf("Error creating BST");
		return 0;
	}
	readFileBST(contactBST);
	while(quitStatus == 0){
		inputStatus = 0;
		while(inputStatus == 0){ //Looping until choice is entered correctly
			printf("\nPlease select: (a) add, (d) delete, (l) lookup, or (q) quit: ");
			fflush(stdin);
			scanf("%c",&userInput);
			if(userInput == 'a' || userInput == 'd' || userInput == 'l' || userInput == 'q'){
				inputStatus = 1;
			}
		}
		printf("Choice: %c\n",userInput);
		if(userInput == 'q'){ //User Quits
				quitStatus = 1;
		}
		else{
			if(userInput == 'a'){
				addName(contactBST);
			}
			else if(userInput == 'd'){
				deleteName(contactBST);
			}
			else if(userInput == 'l'){
				lookupName(contactBST);
			}
		}
	}
	contactBST = destroyBST(contactBST);

	return 0;
}//end main

/*readFileBST: The function will first ask the user for a filename
or allow them to click enter for a default file name. It will then
read from the file and parse the lines into a name, phone number,
and web address and save all three into three seperate strings in
a structure. It will then insert the struct into the BST tree and
create the sorted tree line by line.
Input: contactBST(pointer to BST tree)
Return: Nothing
/*1*/void readFileBST(BST* contactBST)
{
	FILE*fp;
	contactData* dataList;
	char filename[MAX];
	char tempStr[MAX];
	char* parseStr;
	int strlength;
	int recordNum = 0;

	printf("Enter filename or hit <enter> for default name: ");
	fgets(filename,MAX,stdin);
	strlength = strlen(filename);
	if(filename[strlength-1] == '\n'){
		filename[strlength-1] = 0;
	}
	if(strcmp(filename,"\0") == 0){
		printf("Default name used\n");
		strcpy(filename,"in.txt");
	}
	fp = fopen(filename,"r");
	while(fp == NULL){
		printf("Enter filename or hit <enter> for default name: ");
		fgets(filename,MAX,stdin);
		strlength = strlen(filename);
		if(filename[strlength-1] == '\n'){
			filename[strlength-1] = 0;
		}
		if(strcmp(filename,"\0") == 0){
			printf("Default name used\n");
			strcpy(filename,"in.txt");
		}
		fp = fopen(filename,"r");
	}
	while((fgets(tempStr,MAX,fp))!= NULL){ 
		dataList = (contactData *)malloc(sizeof(contactData));
		if(dataList == NULL){
			printf("Memory could not be allocated correctly");
			exit(0);
		}
		parseStr = strtok(tempStr,",");
		strcpy(dataList->name,parseStr);
		parseStr = strtok(NULL,",\n");
		strcpy(dataList->phoneNum,parseStr);
		parseStr = strtok(NULL,",\n");
		if(parseStr == NULL){
			strcpy(dataList->webAddr,"");
		}
		else{
			strcpy(dataList->webAddr,parseStr);
		}
		insertBST(contactBST,(void*)dataList);
		recordNum++;
	}
	printf("Read in %d records\n\n",recordNum);
	inOrder(contactBST,printTree);
}//end readFileBST

/*compareWord: This function is the parameter function used in the BST to
compare the names for sorting
Input: name1(void*), name2(void*)
Return: result(int)
/*2*/int compareWord(void* name1, void* name2) //From Lab3, Not sure if this works for Lab4
{
	char*word1;
	char*word2;
	int result;

	word1 = ((contactData *)name1)->name;
	word2 = ((contactData *)name2)->name;
	result = strcmp(word1,word2);

	return result;
}//end compareWord

/*printTree: This is the processing function that is used by
the inOrder traversing BST function. It will print the data
contained in the current node.
Input: dataInPtr(void*)
Return: Nothing
/*3*/void printTree(void* dataInPtr){
	char*word1;
	char*word2;
	char*word3;

	word1 = ((contactData *)dataInPtr)->name;
	word2 = ((contactData *)dataInPtr)->phoneNum;
	word3 = ((contactData *)dataInPtr)->webAddr;

	printf("%-18s\t%-12s   %-s\n",word1,word2,word3);
}//end printTree

/*addName: This function is called when the user wants to add to the BST
It will ask the user for a name, phone, and web address to add and if the
name already exists in the BST then it will not add it and let the user
know that there is a duplicate.
Input: contactBST(point to BST Tree)
Return: Nothing
/*4*/void addName(BST* contactBST) //Add is not working, something in the bst.c files's insert function is not working in the recursion
{			//I think it is the fact that a new node is created first so when there is a duplicate and we don't want to add the node then its just
			//Sitting there and it breaks the tree.
	contactData* dataList;
	int addStatus;
	int strlength;

	dataList = (contactData*)malloc(sizeof(contactData));
	if(dataList == NULL){
			printf("Memory could not be allocated correctly");
			exit(0);
	}
	fflush(stdin);
	printf("Enter name: ");
	fgets(dataList->name,MAX,stdin);
	strlength = strlen(dataList->name);
	if(dataList->name[strlength-1] == '\n'){
		dataList->name[strlength-1] = 0;
	}
	printf("Enter phone: ");
	fgets(dataList->phoneNum,MAX,stdin);
	strlength = strlen(dataList->phoneNum);
	if(dataList->phoneNum[strlength-1] == '\n'){
		dataList->phoneNum[strlength-1] = 0;
	}
	printf("Enter web address or hit <enter> for no address: ");
	fgets(dataList->webAddr,MAX,stdin);
	strlength = strlen(dataList->webAddr);
	if(dataList->webAddr[strlength-1] == '\n'){
		dataList->webAddr[strlength-1] = 0;
	}
	addStatus = insertBST(contactBST,(void*)dataList);
	if(addStatus == -1){ 
		printf("%s is already in the contact list\n", dataList->name);
	}
	else if(addStatus == 0){
		printf("Failed inserting, overflow\n");
	}
	else{
		printf("%s added\n",dataList->name);
	}
}//end addName

/*deleteName: This function is called when the user wants to delete
from the BST. It will first ask the user a name. If the name doesn't
exist in the BST then it will let the user know that it doesn't exist
and then print the BST records alphabetically. If it does exist, then
a confirmation message appears
Input: contactBST(pointer to BST Tree)
Return: Nothing
/*5*/void deleteName(BST* contactBST)
{
	char inputStr[MAX];
	contactData * dataList;
	int strlength;
	int sucStatus = 0;
	
	while(sucStatus == 0){
		fflush(stdin);
		printf("Enter name to delete: ");
		fgets(inputStr,MAX,stdin);
		strlength = strlen(inputStr);
		if(inputStr[strlength-1] == '\n'){
			inputStr[strlength-1] = 0;
		}
		sucStatus = deleteBST(contactBST,(void*)inputStr,(void**)&dataList); 
		if(sucStatus == 1){
			printf("Deleted record: %s, %s %s\n", dataList->name, dataList->phoneNum, dataList->webAddr);
		}
		else{
			printf("%s not found\n\n",inputStr);
			inOrder(contactBST,printTree);
			printf("\n");
		}
	}
}//end deleteName

/*lookupName: This function is called when the user wants to
lookup a contact info from the BST Tree and will allow the
user to modify the looked up info. It will first prompt the user 
for a name and then if its found, ask the user if they want to modify
it. If yes then the user can change the name or the phone number and
web address.
Input: contactBST (pointer to BST Tree)
Return: Nothing
/*6*/void lookupName(BST* contactBST)
{
	char inputStr[MAX];
	char changeRec, changeWhich;
	contactData* dataList;
	int strlength;
	int sucStatus = 0;

	while(sucStatus == 0){
		fflush(stdin);
		printf("Enter name to look up: ");
		fgets(inputStr,MAX,stdin);
		strlength = strlen(inputStr);
		if(inputStr[strlength-1] == '\n'){
			inputStr[strlength-1] = 0;
		}
		sucStatus = deleteBST(contactBST,(void*)inputStr,(void**)&dataList); 
		if(sucStatus == 0){
			printf("%s cannot be found in list\n\n",inputStr);
			inOrder(contactBST,printTree);
			printf("\n");
		}
		else{
			printf("%-18s\t%s   %s\n", dataList->name, dataList->phoneNum, dataList->webAddr);
			printf("Change record? [y/n]: ");
			scanf(" %c",&changeRec); 
			if(changeRec == 'y' || changeRec == 'Y'){
				printf("n. change name\nc. change contact info\n");
				fscanf(stdin," %c",&changeWhich);
				if(changeWhich == 'n'){
					fflush(stdin);
					printf("Enter name: ");
					fgets(inputStr,MAX,stdin);
					strlength = strlen(inputStr);
					if(inputStr[strlength-1] == '\n'){
						inputStr[strlength-1] = 0;
					}
					strcpy(dataList->name,inputStr);
					insertBST(contactBST,(void*)dataList);
				}
				else if(changeWhich == 'c'){
					fflush(stdin);
					printf("Enter phone or hit <enter> for no change: ");
					fgets(inputStr,MAX,stdin);
					strlength = strlen(inputStr);
					if(inputStr[strlength-1] == '\n'){
						inputStr[strlength-1] = 0;
					}
					if(strcmp(inputStr,"\0") != 0){ //Means user wants a change
						strcpy(dataList->phoneNum,inputStr);
					}
					fflush(stdin);
					printf("Enter web address or hit <enter> for no change: ");
					fgets(inputStr,MAX,stdin);
					if(inputStr[strlength-1] == '\n'){
						inputStr[strlength-1] = 0;
					}
					if(strcmp(inputStr,"\0") != 0){ //Means user wants a change
						strcpy(dataList->webAddr,inputStr);
					}
				}
			}
			insertBST(contactBST,(void*)dataList);
		}
	}
}//end lookupName