//
//  output.c
//  CIS15C_TeamProject
//
//  Created by Evan Chen on 5/29/13.
//  Copyright (c) 2013 Evan Chen. All rights reserved.
//

#include <stdio.h>
#include "twitterTrender.h"

void displayHash(USERNAME usernameHash[])
{
    int i;
    TWITTERDATA* currentData;
    
    // Loop hash array to find each user
    for (i = 0; i < MAX_HASH; i++)
    {
        // If data exists in hash index
        if (usernameHash[i].filled == 1)
            // Loop through all tweets of current user
            while (stackCount(usernameHash[i].data) > 0)
            {
                // Get current tweet
                currentData = (TWITTERDATA*)popStack(usernameHash[i].data);
                
                // Print tweet
                printf("%s,%s,%d,%s\n", usernameHash[i].username, currentData->date, currentData->numberOfRetweets, currentData->tweet);
            }// end while
    }// end for
}// end displayHash