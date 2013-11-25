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
/*3*/void addName(BST* contactBST);
/*4*/void deleteName();
/*5*/void lookupName();

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
			printf("Please select: (a) add, (d) delete, (l) lookup, or (q) quit: "); 
			scanf("%c",&userInput);
			if(userInput == 'a' || userInput == 'd' || userInput == 'l' || userInput == 'q'){
				inputStatus = 1;
			}
		}
		printf("Choice: %c",userInput);
		if(userInput == 'q'){ //User Quits
				quitStatus = 1;
		}
		else{
			if(userInput == 'a'){
				addName(contactBST);
			}
			else if(userInput == 'd'){
				//delete function here
			}
			else if(userInput == 'l'){
				//look up function here
			}
		}
	}

	contactBST = destroyBST(contactBST); //Not sure of this
	return 0;
}

/*1*/void readFileBST(BST* contactBST)
{
	FILE*fp;
	contactData dataList;
	char filename[30];
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
		parseStr = strtok(tempStr,",");
		strcpy(dataList.name,parseStr);
		parseStr = strtok(NULL,",\n");
		strcpy(dataList.phoneNum,parseStr);
		parseStr = strtok(NULL,",\n");
		if(parseStr == NULL){
			strcpy(dataList.webAddr,"");
		}
		else{
			strcpy(dataList.webAddr,parseStr);
		}
		insertBST(contactBST,(void*)dataList.name,(void*)dataList.phoneNum,(void*)dataList.webAddr); //NEED TO CHECK IF SUCCESSFULLY INSERTED OR NOT (CHECK INT RETURNED)
		recordNum++;
	}
	printf("Read in %d records\n",recordNum);
}

/*2*/int compareWord(void* name1, void* name2) //From Lab3, Not sure if this works for Lab4
{
	char*word1;
	char*word2;
	int result;

	word1 = (char*)name1;
	word2 = (char*)name2;
	result = strcmp(word1,word2);

	return result;
}//end compareWord

/*3*/void addName(BST* contactBST)
{
	contactData dataList;
	int addStatus;

	printf("Enter name: ");
	fgets(dataList.name,MAX,stdin);
	printf("Enter phone: ");
	fgets(dataList.phoneNum,MAX,stdin);
	printf("Enter web address or hit <enter> for no address: ");
	fgets(dataList.webAddr,MAX,stdin);

	addStatus = insertBST(contactBST,(void*)dataList.name,(void*)dataList.phoneNum,(void*)dataList.webAddr);
	if(addStatus == -1){ //NOT in the insertBST function yet, need to incorporate
		printf("Duplicate Record\n");
	}
	else if(addStatus == 1){
		printf("Failed inserting, overflow\n");
	}
	else{
		printf("%s added",dataList.name);
	}

}

/*4*/void deleteName()
{

}

/*5*/void lookupName()
{

}