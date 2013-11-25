/*-------------------------------------------------------------------------
Programmer's Name: Evan Chen
Progam Name: ColorStruct.c
Date: 12/07/12
OS: Windows 7 Enterprise x64, Intel i7, Code::Blocks 10.05
Description: This program will prompt the user for a file and open it. The file
contains color names and their values. After opening the file, the content will
be read into a temporary string. Each of the temporary string's color name and its
respective color values will be read into an element of an array of structs that
contains colorName and colorValue. The colorName and its respective colorValue
in the array of structs will be sorted by color name. It will then be displayed
on stdout and the user will be prompted to look for a color value by its color
name. If the user inputs a correct color name then the respective color value
will be displayed in decimal and hexadecimal format. The program will keep prompting
until the user inputs quit.
----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ARRAY 100
#define MAX_CHARS 101
#define MAX_STRING 256

//Global Declaration
typedef struct{
char*colorName;
int colorValue;
}COLOR;

//Function Prototype Declaration
/*1*/ FILE* openFile(char*,char*);
/*2*/ int readInputColor(COLOR coloArray[]);
/*3*/ void fillColorStruct(char colorTemp[],COLOR coloArray[]);
/*4*/ void colorSort(COLOR coloArray[], int numElems);
/*5*/ void displayColor(COLOR coloArray[], int numElems);
/*6*/ void freeMem(COLOR coloArray[], int numElems);
/*7*/ int strlCmp(const char*,const char*);
/*8*/ void userQuery(COLOR coloArray[], int numElems);
/*9*/ COLOR* searchColor(COLOR coloArray[],int numElems, char tempStr[]);
char* makeString(const char*str);
void nGets(char*input,int numChars);

int main()
{
//Local Declarations
    int numElems;
    COLOR structArray[MAX_ARRAY];

//Statements
    numElems = readInputColor(structArray);
    if(numElems!=0){
        colorSort(structArray,numElems);
        displayColor(structArray,numElems);
        userQuery(structArray,numElems);
        freeMem(structArray,numElems);
    } //end if
    return 0;
}//main

/*--------------------------------------------------------------------------------------------
openFile function
This function prompts user for a file name and reads it into the string called filename.
    If filename is QUIT then the function returns null or else it returns the file name to main.
Receives: string containing prompt for user, string containing the mode for opening file
Returns: the filename (FILE*)
Precondition: MAX_CHARS is defined externally
---------------------------------------------------------------------------------------------*/
/*1*/ FILE* openFile(char*prompt,char*mode) /*string and string*/
{
    FILE*fp; /* local file pointer */
    char filename[MAX_CHARS]=""; /*string that will store user's filename */

    fputs(prompt,stdout); //prints prompt to stdout
    nGets(filename,MAX_CHARS); //reads user's filename into filename (string)
    if (strcmp(filename, "QUIT") == 0) //if filename is QUIT then return NULL
        return NULL; //end if
    fp = fopen(filename, mode); //opens the filename with the mode paramater
    return fp;
} /*end openFile*/

/*--------------------------------------------------------------------------------------------
readInputColor function
This function prompts the user to input a file which will be read into a local string. If it
    is opened successfully then the temporary string and current element of the array of COLOR
    structs will be passed to another function called fillColorStruct. This function will continue
    to pass the temp. string and current element of array of COLOR structs to fillColorStruct
    until EOF, when max # of elements reached, or memory is not alloctaed correctly in
    fillColorStruct. This function will return the number of elements or 0 if the file did not
    open correctly.
Receives: structArray(array of COLOR structs)
Returns: int
Precondition: structArray is declared, MAX_STRING,MAX_ARRAY are predefined
---------------------------------------------------------------------------------------------*/
/*2*/ int readInputColor(COLOR coloArray[]) /*array of COLOR structs*/
{
    FILE*colorFile; //local FILE*
    int i = 0;
    int numElems = 0;
    char colorTemp[MAX_STRING]; //local string for the file name

    colorFile = openFile("Please enter the filename: ", "r"); //open file inputted by user
    if(colorFile==0)
        return 0; //end if
    while(fgets(colorTemp,MAX_STRING,colorFile)!= NULL && numElems<MAX_ARRAY){ //WHILE loop until EOF or max elements reached
        fillColorStruct(colorTemp,coloArray+i);
        if((coloArray->colorName)== NULL) //if memory wsa not allocated correctly then WHILE loop will end.
            break; //end if
        ++i;
        ++numElems;
    } //end while
    fclose(colorFile); //close user's file
    return numElems;
}/*end readInputColor*/

/*--------------------------------------------------------------------------------------------
fillColorStruct function
This function will split the temporary string into color name and color value. Memory will be
    allocated for the colorName located in the array of COLOR structs. If memory is not allocated
    correctly then the current element of the array of COLOR structs will be assigned NULL
    the respective color value will be assigned into colorValue in the array of COLOR structs
Receives: colorTemp(string), coloArray(array of COLOR structs)
Returns: None
Precondition: colorTemp is defined and initialized and coloArray is defined
---------------------------------------------------------------------------------------------*/
/*3*/ void fillColorStruct(char colorTemp[], COLOR coloArray[]) /*string, array of COLOR structs*/
{
    char*ps; //local pointer to char
    int temp;

    ps = strtok(colorTemp,"\t");
    coloArray->colorName = makeString(ps); //allocates memory for the colorName located in array of COLOR structs and assigns the color name to it.
    if(!(coloArray->colorName))
        (coloArray->colorName) = NULL; //end if
    ps = strtok(NULL,"\n");
    coloArray->colorValue = atoi(ps); //assigns the color value to colorValue located in array of COLOR structs
}/*end fillColorStruct*/

/*--------------------------------------------------------------------------------------------
colorSort function
This function will sort the colorName and colorValue both located in the array of COLOR struct
Receives: coloArray(array of COLOR struct), numElems(int)
Returns: None
Precondition: colorName and colorValue in coloArray have been declared and initialized,
numElems has been declared and initialized
---------------------------------------------------------------------------------------------*/
/*4*/ void colorSort(COLOR coloArray[], int numElems) /* array of COlOR structs, int*/
{
    int c,d; //local variable for loops
    char*nametemp; //temporary string for sorting colorName
    int valuetemp; //temporary int for sorting colorValue

    for (c = 1 ; c <= numElems - 1; c++) {
        d = c;
        while ( d > 0 && strlCmp((coloArray+d)->colorName, (coloArray+(d-1))->colorName)<0) {
            nametemp = (coloArray+d)->colorName;            //Sorts colorName in the array of COLOR structs
            (coloArray+d)->colorName = (coloArray+(d-1))->colorName;
            (coloArray+(d-1))->colorName = nametemp;

            valuetemp = (coloArray+d)->colorValue;         //Sorts colorValue in the array of COLOR structs
            (coloArray+d)->colorValue = (coloArray+(d-1))->colorValue;
            (coloArray+(d-1))->colorValue = valuetemp;
        d--;
        }// end while
    }// end for
}/*end colorSort*/

/*------------------------------------------------------------------------------------------------
displayColor function
This function first prints a header and then displays the colorNames from array of COLOR structs
    with its respective colorValue from array of COLOR structs under the header.
Receives: coloArray(array of COLOR structs), numElems(int)
Returns: None
Precondition: colorName and colorValue in array of COLOR structs have been declared and initialized,
numElems has been declared and initialized
---------------------------------------------------------------------------------------------------*/
/*5*/ void displayColor(COLOR coloArray[], int numElems) /*array of COLOR structs,int*/
{
    int i;

    printf("\nCOLOR NAME\t\tNUMBER (Decimal)\tNUMBER (Hexadecimal)\n\n"); //prints the header
    for(i=0; i<numElems; ++i){
        printf("%-22s", (coloArray+i)->colorName); //prints colorName from array of COLOR structs
        printf("\t%15d\t", (coloArray+i)->colorValue); //prints colorValue from array of COLOR structs as decimal
        printf("\t %06X\n", (coloArray+i)->colorValue); //prints colorValue from array of COLOR structs as hexadecimal
    } // end for
}/*end displayColor*/

/*------------------------------------------------------------------------------------------------
freeMem function
This function frees dynamically allocated memory of the parameter
Receives: coloArray(array of COLOR structs),numElems(int)
Returns: None
Precondition: coloArray has been declared and initialized, numElems has been declared and initialized
---------------------------------------------------------------------------------------------------*/
/*6*/ void freeMem(COLOR coloArray[], int numElems) /*array of COLOR structs, int*/
{
    int i; //local variable for loop

    for(i=0;i<numElems;++i){
        free(((coloArray+i)->colorName));
    } // end for
}/*end freeMem*/

/*------------------------------------------------------------------------------------------------
strlCmp function
This function compares the parameters and disregards the case. It returns positive,0,or negative number
    based on if one is bigger or smaller.
    This function will be used for sorting
Receives: colorName1(array of pointers),colorName2(array of pointers)
Returns: int
Precondition: colorName1 and colorName2 have been declared and initialized
---------------------------------------------------------------------------------------------------*/
/*7*/ int strlCmp(const char*colorName1,const char*colorName2) /*array of pointers, array of pointers*/
{
    while(tolower(*colorName1) == tolower(*colorName2) && *colorName1 != '\0'){ //compares by lowercase
        ++colorName1;
        ++colorName2;
    }//end while
    return tolower(*colorName1)-tolower(*colorName2);
}/*end strlCmp*/

/*------------------------------------------------------------------------------------------------
userQuery function
This function prompts user for a color name to search for. It then passes the colorName to another
    function for searching and as a result, displays the respective color value decimal and
    hexadecimal to stdout. If the color is not found it will display that it is not found. The
    function continues to prompt until the user inputs quit.
Receives: coloArray(array of COLOR structs), numElems(int)
Returns: None
Precondition: coloArray and numElems have been declared and initialized
---------------------------------------------------------------------------------------------------*/
/*8*/void userQuery(COLOR coloArray[], int numElems) /*array of COLOR structs, int*/
{
    int i = 0;
    char tempStr[MAX_STRING]; //temporary string
    COLOR*ps; //pointer to COLOR struct

    printf("\nPlease enter a color name (Quit to quit): "); //prompt user for color name
    nGets(tempStr,MAX_CHARS);
    while(strlCmp("Quit",tempStr)!=0){ //while loop until user inputs quit
        fflush(stdin);
        ps = searchColor(coloArray,numElems,tempStr);
        if(ps==NULL)
            printf("%s not found\n",tempStr);
        if(ps!=NULL){
            printf("%s = %d (%06X in Hexadecimal)\n",ps->colorName,ps->colorValue,ps->colorValue);
        }
    fflush(stdin);
    printf("\nPlease enter a color name (Quit to quit): ");
    nGets(tempStr,MAX_CHARS);
    }// end while
}/*end userQuery*/

/*------------------------------------------------------------------------------------------------
searchColor function
This function uses the user's input color name and searches for it in the array of COLOR structs
    with a sequential search. It returns a pointer to where it is located in the array of COLOR structs
Receives: coloArray(array of COLOR structs), numElems(int), tempStr(string)
Returns: pointer to COLOR
Precondition: coloArray,numElems,tempStr have been declared and initialized
---------------------------------------------------------------------------------------------------*/
/*9*/ COLOR* searchColor(COLOR coloArray[],int numElems, char tempStr[]) /*array of COLOR structs,int,string*/
{
    COLOR* ps; //local pointer to COLOR
    ps = coloArray; //assigns address of coloArray to ps
    int i; //local variable for loop

    for(i=0;i<numElems;++i){
        if(strlCmp((ps+i)->colorName,tempStr)==0)
            return ps+i;
    }
    return NULL;
}/*end searchColor*/

/*------------------------------------------------------------------------------------------------
makeString function
This allocates memory for the parameter. If successful, the data is copied from the parameter into
    a local pointer to char and returned
Receives: str(constant pointer to char)
Returns: ps(char*)
Precondition: str is declared and initialized
---------------------------------------------------------------------------------------------------*/
char* makeString(const char*str) /*pointer to char*/
{
    char* ps; //local pointer to char

    ps=(char*)malloc(strlen(str)+1); //allocating memory for ps
    if(ps!=NULL){
        strcpy(ps,str);
    }
    return ps;
}/*end makeString*/

/*------------------------------------------------------------------------------------------------
nGets function
This function reads a strings from stdin into the parameter pointer to string and replaces the newline
    with a '\0'
Receives: input(char*),numChars(int)
Returns: None
Precondition: input has been declared, numChars has been declared and initialized
---------------------------------------------------------------------------------------------------*/
void nGets(char*input,int numChars) /* char*,int */
{
    int size;

    fgets(input,numChars,stdin);
    size = strlen(input);
    if(input[size-1]=='\n') // Looks to see if the last character of the string is a newline
        input[size-1]='\0'; //If it is, the newline is change into a \0.
}/*end nGets*/
