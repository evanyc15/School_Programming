//
//  getData.c
//  CIS15C_TeamProject
//
//  Created by Evan Chen on 5/29/13.
//  Copyright (c) 2013 Evan Chen. All rights reserved.
//

#include <stdio.h>
#include "twitterTrender.h"

int getData(BST * usernameBST, USERNAME* usernameHash[])
{
    FILE* fp = NULL;
    //char line[2000];
    char username[MAX_USERNAME_LEN];
    char tweet[MAX_TWEET_LEN];
    TWITTERDATA* newData = NULL;
    USERNAME* currentUser = NULL;
    int homeAddress = 0;
    int i;
    char tempDate[50];
    int tempNumTweet;
    
    // Initialize hash
    for (i = 0; i < MAX_HASH; i++)
    {
        // ...then create new user
        if ((currentUser = (USERNAME*)malloc(sizeof(USERNAME))) == NULL)
            exit(1);
        
        usernameHash[i] = currentUser;
        usernameHash[i]->filled = 0;
    }// end for
    
    // Open file
    if ((fp = fopen("TwitterData.txt","r")) == NULL)
        return 1;
    
    while(fscanf(fp,"%[^,]%*c%[^,]%*c%d%*c%[^\n]\n",username, tempDate, &tempNumTweet, tweet)!=EOF)
    //while(fgets(line,2000,fp) != NULL)
    {
        // Allocate memory for new node
        if ((newData = (TWITTERDATA*)malloc(sizeof(TWITTERDATA))) == NULL)
            exit(1);
    
        // Parse line
        /*fscanf(fp, "%[^,]%*c", username);
        fscanf(fp, "%[^,]%*c", newData->date);
        fscanf(fp, "%d%*c", &newData->numberOfRetweets);
        fscanf(fp, "%[^\n]", tweet);*/
        
        //fscanf(fp,"%[^,],%[^,],%d,%[^\0]",username, newData->date, &newData->numberOfRetweets, tweet);
        
        strcpy(newData->date,tempDate);
        newData->numberOfRetweets = tempNumTweet;
        
        // Get home address
        homeAddress = (int)getHomeAddress((unsigned char*)username, *usernameHash);
        
        // Get get current user
        currentUser = usernameHash[homeAddress];
        
        // If user doesn't exist
        if (usernameHash[homeAddress]->filled == 0)
        {
            // Dynamically allocate memory for username and copy into node
            if ((currentUser->username = (char*)malloc(strlen(username+1))) == NULL)
                exit(1);
            strcpy(currentUser->username, username);
            
            // Set value to filled
            currentUser->filled = 1;
            
            // Create heap of data
            currentUser->data = createStack();
            
            // Add to hash
            usernameHash[homeAddress] = currentUser;
        }// end if
        
        // Dynamically allocate memory for tweet and copy into node
        if ((newData->tweet = (char*)malloc(strlen(tweet+1))) == NULL)
            exit(1);
        
        strcpy(newData->tweet,tweet);
        // Add new data into heap
        pushStack(currentUser->data, newData);
        
        
    }// end while
    
    // Close file
    fclose(fp);
    
    return 0;
}// end getData

