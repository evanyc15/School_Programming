


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


/*1*/void readFileBST(contactData* dataList[], BST* contactBST);
/*2*/int compareWord(void* name1, void* name2);
/*3*/void addName();
/*4*/void deleteName();
/*5*/void lookupName();

int main(void){
	contactData* dataList[MAX];
	BST* contactBST; //NOT sure if these are right
	char userInput;
	int inputStatus;
	int quitStatus = 0;
	

	contactBST = createBST(compareWord);
	readFileBST(dataList,contactBST);
	while(quitStatus = 0){
		inputStatus = 0;
		while(inputStatus == 0){ //Looping until choice is entered correctly
			printf("Please select from the following: (a) add, (d) delete, (l) lookup, or (q) quit:"); 
			scanf("%c",userInput);
			if(userInput == 'a' || userInput == 'd' || userInput == 'l' || userInput == 'q');
				inputStatus = 1;
			}
		if(userInput == 'q'){ //User Quits
			quitStatus = 1;
		}
		else{
			if(userInput == 'a'){
				//add function here
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

/*1*/void readFileBST(contactData* dataList[], BST* contactBST)
{
	FILE*fp;
	char filename[30];
	int index = 0;
	
	printf("Enter filename (or hit enter for default):");
	fscanf(stdin,"%s",filename);
	if(strcmp(filename,"")==0){
		strcpy(filename,"in.txt");
	}
	fp = fopen(filename,"r");
	while((fscanf(fp,"%[^,],%[^,],%s",dataList[index]->name,
		dataList[index]->phoneNum,dataList[index]->webAddr))!=EOF){//Not sure if this works cause not all lines have web address
	


	}
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

/*3*/void addName()
{

}

/*4*/void deleteName()
{

}

/*5*/void lookupName()
{

}