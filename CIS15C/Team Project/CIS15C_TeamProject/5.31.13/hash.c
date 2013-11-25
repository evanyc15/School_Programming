//
//  hash.c
//  CIS15C_TeamProject
//
//  Created by Evan Chen on 5/29/13.
//  Copyright (c) 2013 Evan Chen. All rights reserved.
//

#include "twitterTrender.h"

unsigned int getHomeAddress(unsigned char*str, USERNAME usernameHash[])
{
    unsigned int homeAddress = 0;
    int qProbe = 1;
    
    //assigns first homeAddress
    homeAddress = _hash((unsigned char*)str);
    
    //loop until collision is cleared using quad probing
    while(usernameHash[homeAddress].filled == 1 && strcmp(usernameHash[homeAddress].username, (char*)str) != 0)
    {
        //assigning new index with quad probing
        homeAddress = homeAddress + (qProbe * qProbe);
        
        //if out of bounds, then modulo to bring back into bounds
        while(homeAddress > MAX_HASH)
            homeAddress = homeAddress % MAX_HASH;
        
        //move to next quad probe
        qProbe++;
    }

    return homeAddress;
}// end getHomeAddress

unsigned int _hash(unsigned char *str)
{
    unsigned int hash = 5381;
    int c;
    
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    
    return (hash) % MAX_HASH;
}// end _hash



