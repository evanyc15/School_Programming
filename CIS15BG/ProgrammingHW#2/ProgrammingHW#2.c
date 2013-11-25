/* Name of Program: FileEncoder
Programmer's Name: Evan Chen
Current Date: 10/24/2012
OS & Compiler: Windows 7 Ultimate 64-Bit & Code Blocks 10.05

This program will use the codes stored in a file to encode a file respectively and
then decode it afterwards to test it. It will begin by reading two strings
from a text file. After this, the program will go into a loop to open thes
files and begin encoding, decoding, or exiting the program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_CHARS 101


//Prototypes
/*A*/ FILE* OpenFile(char*, char*);
/*B*/ bool ReadCodeFile(FILE*,char*, char*);
/*C*/ void ReadChar(FILE*,FILE*,char*,char*);
/*D*/ char EncodeFile(char,char*,char*);
/*E*/ void DecodeFile(FILE*,FILE*,char*,char*);
/*F*/ bool chkDuplicate(char*);
void nGets(char*,int);

int main()
{
//Local Declarations of main
    char actualStr[MAX_CHARS]="";
    char codeStr[MAX_CHARS]="";
    char forEncodingStr[MAX_CHARS]="";
    FILE*infile;
    FILE*outfile;
    FILE*codefile;

//Prompt user for code file name and read into two strings.
    while(ReadCodeFile(codefile,actualStr,codeStr));
    fputs("Code File Read Successfully\n",stdout);
//while loop until the user inputs QUIT or file is NULL
    while ((infile = OpenFile("Enter the name of the file to encode (or QUIT to end program): ", "r")) != NULL &&
           (outfile = OpenFile("Enter the name of the file to store the encoded data (or QUIT to end the program): ", "w+")) != NULL)
    {
        ReadChar(infile,outfile,actualStr,codeStr); //reads infile and outfile and uses the actualStr/codeStr to encode the infile and print to outfile
        DecodeFile(infile,outfile,actualStr,codeStr); //Decodes outfile by using actualStr and codeStr and compares if it is the same as the text in infile. Prints the decoded line onto standard output
        fclose(infile);
        fclose(outfile);
    }
    puts("\nEnding program.");
    return 0;
}

//Prompts the user to enter a file name and the fopens the file with the mode string parameter.
//If user inputs quit, the function returns null or else it opens and returns the file.
/*A*/ FILE* OpenFile(char*prompt,char*mode)
{
    FILE*fp;
    char filename[MAX_CHARS]="";

    fputs(prompt,stdout); //Prints the prompt to the screen
    nGets(filename,MAX_CHARS); //Function to save the user input into a string and remove the newline
    if (strcmp(filename,"QUIT") == 0) //If the user inputs QUIT then it will return NULL or else it will return the file name.
        return NULL;
    fp = fopen(filename, mode);
    return fp;
}


//This function reads the code file that the user inputs into a two strings.
//One string is for the original characters and one for their respective characters.
//This function also calls another function to check for duplicates and this function checks that the strings are the same size
/*B*/ bool ReadCodeFile(FILE*codefile,char*actualStr,char*codeStr)
{
    codefile = OpenFile("Enter the code filename: ","r"); //Calls the openfile function and assigns the file to codefile.
    fgets(actualStr,MAX_CHARS,codefile); //Reads the original line into a string
    fgets(codeStr,MAX_CHARS,codefile); //Reads the respective code line into a string
    fclose(codefile);
    if(strlen(actualStr)!=strlen(codeStr)||chkDuplicate(actualStr)||chkDuplicate(codeStr)) //if the sizes of both strings are not the same or there are duplicates then it will return false
    {
        return false;
    }
    return true;
}

//This function reads char by char from a file and then calls another function to encode the chars into their respective encoded char
/*C*/ void ReadChar(FILE*infile,FILE*outfile,char*actualStr,char*codeStr)
{
    int i;
    char encode[MAX_CHARS]="";

    while(fgets(encode,MAX_CHARS,infile) != NULL) //This will read the infile into a string until there is an error or EOF which it will then stop the while loop
    {
        for (i = 0; i < strlen(encode); i++)
            encode[i] = EncodeFile(encode[i],actualStr,codeStr); //Reading char by char, EncodeFile is called to encode char by char and put each encoded char into the encode string
        fputs(encode, outfile); //prints the encode string into outfile
    }
}

//This function is called by the previous one above and matches the original char with the encoded char.
//If the char cannot be matched with any encoded char than the original char is returned.
//If it is matched then the encoded char is returned.
/*D*/ char EncodeFile(char origChar,char*actualStr,char*codeStr)
{
    int numChars = strlen(actualStr); //Reads how many characters are in actualStr
    int index = 0;
    while (origChar != actualStr[index]) { //While loop continues to run as long as the origChar is not actual to actualStr to the index given.
        ++index;
        if (index == numChars - 1) //If no origchar is matched up with any of the chars in the actualStr then origChar will be returned.
            return origChar;
    }
    return codeStr[index]; //Returns the respective encoded char.
}

//This function will decode the encoded file by calling the function above and matching the encoded chars
//with the original char. It then prints out the decoded string.
/*E*/ void DecodeFile(FILE*infile,FILE*outfile,char*actualStr,char*codeStr)
{
    int i;
    char filetoEncodeStr[MAX_CHARS]="";
    char decodeStr[MAX_CHARS]="";

    fputs("\nResults of encoding check:\n", stdout);
    rewind(infile); //Rewinds the infile and outfile to point to the beginning of the files
    rewind(outfile);
    while(fgets(filetoEncodeStr,MAX_CHARS,infile)!=NULL && fgets(decodeStr,MAX_CHARS,outfile)!=NULL) //As long as both do not read errors or EOF, the while loop will continue
    {
        for(i=0;i<strlen(decodeStr);++i)
            decodeStr[i]=EncodeFile(decodeStr[i],codeStr,actualStr); //Uses the encoding function to now decode by returning the original respective character
        if(strcmp(decodeStr,filetoEncodeStr)==0) //Checks if the decoded string is the same as the original string from the file the user wished to have encoded
        {
            if(decodeStr[strlen(decodeStr)-1]=='\n') //In order to print (correct coding) right after the decoded string is printed on the screen,
                decodeStr[strlen(decodeStr)-1]='\0'; //this looks to see if the last character of the decoded string is a newline or not.
            strcat(decodeStr,"(correct coding)\n"); //if it is, the newline will be replaced with \0
        }
    fputs(decodeStr,stdout); //Prints decoded string onto the standard output
    }
}

//This function checks for duplicates in one string
/*F*/ bool chkDuplicate(char*chkStr)
{
    int i;
    int j;
    int numChars;
    char char1;
    char char2;

    numChars = strlen(chkStr); //Obtains the number of characters in chkStr
        for(i=0;i<numChars;i++){ //Checks through the whole string by comparing char by char to see if there are any duplicate chars in chkStr
            for(j=i+1;j<numChars-1;j++){
                if(chkStr[i]==chkStr[j])
                    return false;
            }
        }
    return true;
}


//This function will delete the \n and \r so that a full file can be read into a string.
void nGets(char*input,int numChars)
{
    int size;
    fgets(input,numChars,stdin);
    size = strlen(input);
    if(input[size-1]=='\n') // Looks to see if the last character of the string is a newline
    input[size-1]='\0'; //If it is, the newline is change into a \0.
}

