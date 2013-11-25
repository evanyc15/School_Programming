#include <stdio.h>
#include <stdlib.h>

int main()
{
	read3Strings(INFO_STRUCT);
}


typedef struct {
char*name;
char*address;
char*city;
}INFO_STRUCT

void read3Strings(INFO_STRUCT*pstu)
{
    char tempStr[MAX]="";

	printf("Enter name: ");
	myGets(tempStr,MAX);
	pstu->name = makeString(tempStr);
	printf("Enter address: ");
	myGets(tempStr, MAX);
	pstu->address = makeString(tempStr);
	printf("Enter city: ");
	myGets(tempStr, MAX);
	pstu->city = makeString(tempStr);
}

