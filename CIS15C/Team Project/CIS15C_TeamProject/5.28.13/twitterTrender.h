//
//  twitterTrender.h
//  CIS15C_TeamProject
//
//  Created by Evan Chen on 5/29/13.
//  Copyright (c) 2013 Evan Chen. All rights reserved.
//

//#include "wrapper.h"
#include "stack.h"
#include "bst.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef CIS15C_TeamProject_twitterTrender_h
#define CIS15C_TeamProject_twitterTrender_h

#endif




#define MAX_TWEET_LEN 121
#define MAX_USERNAME_LEN 15
#define MAX_HASH 1000

typedef struct Username
{
	char* username;// Username of twitter account; unique key
    int filled; // If filled then filled = 1
	STACK* data;// Pointer to twitter data of user; Stack change to heap
}USERNAME;

typedef struct TwitterData
{
	char date[15];// DateTime formatt: mm/dd/yyyy, hh:dd:mm:ss
	int numberOfRetweets; // Used to check popularity of tweet
	char* tweet;// Tweet content
}TWITTERDATA;

int getData(BST * usernameBST, USERNAME* usernameHash[]);
void UIFunction(BST * usernameBST, USERNAME usernameHash[]);
void newData(BST * usernameBST, USERNAME usernameHash[]);
void deleteData(BST * usernameBST, USERNAME usernameHash[]);
void displayHash(USERNAME usernameHash[]);
void displayBST(BST * usernameBST);
void displayOne(USERNAME username[]);
void outputToFile(BST* usernameBST);
unsigned long _hash(unsigned char *str);
void undoDelete(STACK* undoStack);
void printEfficiency(USERNAME username[]);
void freeData(BST * usernameBST, USERNAME usernameHash[]);
int cmpUsername(void* name1, void*name2);
int cmpDate(void* date1, void* date2);
int insertHash(USERNAME * usernameHash[], char* username);
unsigned long getHomeAddress(unsigned char *str, USERNAME usernameHash[]);
