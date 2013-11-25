//
//  main.c
//  CIS15C_TeamProject
//
//  Created by Evan Chen on 5/29/13.
//  Copyright (c) 2013 Evan Chen. All rights reserved.
//

#include <stdio.h>
#include "twitterTrender.h"

int main(int argc, const char * argv[])
{
    BST* usernameBST = NULL;
    USERNAME* usernameHash[MAX_HASH];
    int i;
    
    createBST(cmpUsername);
    
    getData(usernameBST, usernameHash);
    
    displayHash(*usernameHash);
    return 0;
}// end main
