#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

#define MAX 100

typedef struct contactData{
char name[80];   //This is the key
char phoneNum[80];   //This is the value
char webAddr[80];	// This is the value as well(optional)
}contactData;


/*1*/void readFileBST(BST* contactBST);
/*2*/int compareWord(void* name1, void* name2);
/*3*/void printTree(void* dataInPtr);
/*4*/void addName(BST* contactBST);
/*5*/void deleteName(BST* contactBST);
/*6*/void lookupName(BST* contactBST);

int main(void)
{
	BST* contactBST; //NOT sure if these are right
	char userInput;
	int inputStatus;
	int quitStatus = 0;

	contactBST = createBST(compareWord);
	readFileBST(contactBST);
	while(quitStatus == 0){
		inputStatus = 0;
		while(inputStatus == 0){ //Looping until choice is entered correctly
			fflush(stdin);
			printf("\nPlease select: (a) add, (d) delete, (l) lookup, or (q) quit: "); 
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
	contactBST = destroyBST(contactBST); //Not working
	return 0;
}

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
	if(fp == NULL){
		printf("Error opening file\n");
	}
	while((fgets(tempStr,MAX,fp))!= NULL){ //Have to use fgets and then strtokenize to parse it
		dataList = (contactData *)malloc(sizeof(contactData));
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
		insertBST(contactBST,(void*)dataList); //NEED TO CHECK IF SUCCESSFULLY INSERTED OR NOT (CHECK INT RETURNED)
		recordNum++;
	}
	printf("Read in %d records\n\n",recordNum);
	inOrder(contactBST,printTree);
}

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

/*3*/void printTree(void* dataInPtr){
	char*word1;
	char*word2;
	char*word3;

	word1 = ((contactData *)dataInPtr)->name;
	word2 = ((contactData *)dataInPtr)->phoneNum;
	word3 = ((contactData *)dataInPtr)->webAddr;

	printf("%-18s\t%s   %s\n",word1,word2,word3);
}

/*4*/void addName(BST* contactBST)
{
	contactData* dataList;
	int addStatus;
	int strlength;

	dataList = (contactData*)malloc(sizeof(contactData));
	fflush(stdin);
	printf("Enter name: ");
	fgets(dataList->name,MAX,stdin);
	strlength = strlen(dataList->name);
	if(dataList->name[strlength-1] == '\n'){
		dataList->name[strlength-1] = 0;
	}
	printf("Enter phone: ");
	fgets(dataList->phoneNum,MAX,stdin);
	printf("Enter web address or hit <enter> for no address: ");
	fgets(dataList->webAddr,MAX,stdin);

	addStatus = insertBST(contactBST,(void*)dataList);
	if(addStatus == -1){ 
		printf("Duplicate Record\n");
	}
	else if(addStatus == 0){
		printf("Failed inserting, overflow\n");
	}
	else{
		printf("%s added\n",dataList->name);
	}
}

/*5*/void deleteName(BST* contactBST)
{
	char inputStr[MAX];

	fflush(stdin);
	printf("Enter name to delete: ");
	fscanf(stdin,"%s",inputStr);

	//Need to now delete the inputStr record and return to user
}

/*6*/void lookupName(BST* contactBST)
{
	char inputStr[MAX];
	char changeRec, changeWhich;

	fflush(stdin);
	printf("Enter name to look up: ");
	fscanf(stdin,"%s",inputStr);
	//print confirmation name and contact info from above here
	printf("Change record? [y/n]: ");
	fscanf(stdin,"%c",changeRec); //Not working cause its not initialized
	if(changeRec == 'y'){
		printf("n. change name\nc. change contact info\n");
		fscanf(stdin,"%c",&changeWhich);
		if(changeWhich == 'n'){
			printf("Enter name: ");
		}
		else if(changeWhich == 'c'){
			printf("Enter phone or hit <enter> for no change: ");
			fgets(inputStr,MAX,stdin);
			//now change the phone number here with BST function
			printf("Enter web address or hit <enter> for no change: ");
			fgets(inputStr,MAX,stdin);
			//now change the webaddress here with BST function
		}
	}
}