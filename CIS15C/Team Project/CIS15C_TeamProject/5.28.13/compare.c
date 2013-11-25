//
//  compare.c
//  CIS15C_TeamProject
//
//  Created by Evan Chen on 5/29/13.
//  Copyright (c) 2013 Evan Chen. All rights reserved.
//

#include <stdio.h>
#include "twitterTrender.h"

int cmpUsername(void* user1, void*user2)
{
    return strcmp((char*)user1, (char*)user2);
}// end cmpUsername