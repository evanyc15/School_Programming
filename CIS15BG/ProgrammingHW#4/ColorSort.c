/*-------------------------------------------------------------------------
Programmer's Name: Evan Chen
Progam Name: ColorSort.c
Date: 11/26/12
OS: Windows 7 Enterprise x64, Intel i7, Code::Blocks 10.05
Description: This program will prompt the user for a file and open it. The file
contains color names and their values. After opening the file, the content will
be read into a temporary string. The color names in the input file will be read
into a newly allocated memory and then will also be assigned to the current
element of a char* array called colorName, the rest of the line will be converted
to ints and stored in an int array called colorValue. The program will then call
a function to sort both colorName and colorValue based on the color names in
colorName. An insertion sort will be used. After everything is sorted, colorName
will be displayed with colorValue in a decimal and hexadecimal format. The
program will then call a function to free up all dynamically allocated memory.
----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ARRAY 100
#define MAX_CHARS 101
#define MAX_STRING 256

//Function Prototype Declaration
/*1*/ FILE* openFile(char*,char*);
/*2*/ int readInputColor(char*colorName[],int colorValue[]);
/*3*/ void colorSort(char*colorName[],int colorValue[],int numElems);
/*4*/ void displayArray(char*colorName[],int colorValue[],int numElems);
/*5*/ void freeMem(void*,int);
/*6*/ int strlCmp(const char*,const char*);
char* makeString(const char*str);

int main()
{
//Local Declarations
    char* colorName[MAX_ARRAY];
    int colorValue[MAX_ARRAY];
    int numElems;

//Statements
    numElems = readInputColor(colorName,colorValue);
    colorSort(colorName,colorValue,numElems);
    displayArray(colorName,colorValue,numElems);
    freeMem(colorName,numElems);
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
    gets(filename); //reads user's filename into filename (string)
    if (strcmp(filename, "QUIT") == 0) //if filename is QUIT then return NULL
        return NULL;
    fp = fopen(filename, mode); //opens the filename with the mode paramater
    return fp;
} /*end openFile*/

/*------------------------------------------------------------------------------------------------
readInputColor function
This function opens a file. Next, it reads the file into a temporary string until the file is EOF or
    the max elements has been reached. The function will then allocate memory for the colorNames array
    and copy the color names from the temporary strings into the newly allocated memory. Each color name
    is followed by a string of numbers which will then be converted into ints and stored into the
    colorValue array. The function will then return the number of elemens of the file or 0 if it did not
    open.
Receives: colorName(array of pointers),colorValue(array of ints)
Returns: numElems(int)
Precondition: colorName and colorValue have been declared, MAX_STRING & MAX_ARRAY is defined externally
---------------------------------------------------------------------------------------------------*/
/*2*/ int readInputColor(char*colorName[],int colorValue[]) /*array of pointers and array of ints*/
{
    FILE* colorFile; //Local FILE*
    int i=0; //Variable for WHILE loop
    int numElems = 0; //value that will be returned at end of function
    char*p; //saves the strings from strtok
    int str_size, namesize, valuesize; //used to determine total, color name, and color value sizes
    char colorTemp[MAX_STRING]; //temporary string

    colorFile = openFile("Please enter the filename: ","r"); //Calls openFile to open the file
    while(fgets(colorTemp,MAX_STRING,colorFile)!=NULL && numElems<MAX_ARRAY){ //Reads from file into colorTemp until EOF or MAX_ARRAY is reached
        str_size = strlen(colorTemp);
        p = strtok(colorTemp,"\t");
        namesize = strlen(p);
        valuesize = str_size-namesize;
        *(colorName+i) = makeString(p);
        p = strtok(NULL,"\n");
        colorValue[i] = atoi(p); //converts string of numbers into an int
        ++numElems;
        ++i;
    }
    fclose(colorFile);
    return numElems;
}/*end readInputColor*/

/*------------------------------------------------------------------------------------------------
colorSort function
This function will sort the colorName and colorValue.
Receives: colorName(array of pointers),colorValue(array of ints), numElems(int)
Returns: none
Precondition: colorName and colorValue have been declared and initialized, numElems has been declared
and initialized
---------------------------------------------------------------------------------------------------*/
/*3*/ void colorSort(char*colorName[],int colorValue[],int numElems) /*array of pointers, array of ints, int*/
{
    bool swapped;
	int i;
	int lastIndex=numElems-1;
	char *nametemp; //temporary string for switching/sorting the colorName
	int valuetemp; //temporary string for switching/sorting the colorValue

	do {
		swapped = false;
		for( i=0; i < lastIndex; ++i ){
			if( strlCmp(colorName[i], colorName[i+1])>0 ){  //Sorts colorNames
				nametemp= colorName[i];
				colorName[i]=colorName[i+1];
				colorName[i+1]=nametemp;

				valuetemp= colorValue[i];         //Sorts colorValue
				colorValue[i]=colorValue[i+1];
				colorValue[i+1]=valuetemp;

				swapped=true;
			} // end if
		} // end for
		--lastIndex;
	}while( swapped );
}/*end colorSort*/

/*------------------------------------------------------------------------------------------------
displayArray function
This function first prints a header and then displays the colorNames with its respective colorValue
under the header.
Receives: colorName(array of pointers),colorValue(array of ints), numElems(int)
Returns: none
Precondition: colorName and colorValue have been declared and initialized, numElems has been declared and initialized
---------------------------------------------------------------------------------------------------*/
/*4*/ void displayArray(char*colorName[],int colorValue[],int numElems) /*arrays of pointers, arrays of int, int*/
{
    char**cn; //variable for transversing the colorName
    int*cv; //variable for transverse the colorValue
    int*lastp; //variable for the last element

    printf("\nCOLOR NAME\t\tNUMBER (Decimal)\tNUMBER (Hexadecimal)\n\n"); //prints the header
    for(cn=colorName,cv=colorValue, lastp=(colorValue+numElems); cv<lastp; ++cn, ++cv){  //pointer transversal for loop
        printf("%-22s",*cn); //prints colorName
        printf("\t%15d\t", *cv); //prints colorValue as decimal
        printf("\t %06X\n", *cv); //prints colorValue as hexadecimal
    }
}/*end displayArray*/

/*------------------------------------------------------------------------------------------------
freeMem function
This function frees dynamically allocated memory of the parameter
Receives: colorName(array of pointers),numElems(int)
Returns: none
Precondition: colorName has been declared and initialized, numElems has been declared and initialized
---------------------------------------------------------------------------------------------------*/
/*5*/ void freeMem(void*colorName, int numElems) /*pointer to void, int*/
{
    int i;

    for(i=0; i<numElems;i++){
        free((colorName+i)); //free memory
    }
}/*end freeMem*/

/*------------------------------------------------------------------------------------------------
strlCmp function
This function compares the parameters and returns positive, 0, or negative number based on if one is bigger or smaller.
    This function will be used for sorting
Receives: colorName1(array of pointers),colorName2(array of pointers)
Returns: int
Precondition: colorName1 and colorName2 have been declared and initialized
---------------------------------------------------------------------------------------------------*/
/*6*/ int strlCmp(const char*colorName1,const char*colorName2) /*array of pointers, array of pointers*/
{
    while(tolower(*colorName1) == tolower(*colorName2) && *colorName1 != '\0'){ //compares by lowercase
        ++colorName1;
        ++colorName2;
    }//end while
    return tolower(*colorName1)-tolower(*colorName2);
}/*end strlCmp*/

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
