/*-------------------------------------------------------------------------
Programmer's Name: Evan Chen
Progam Name: SimpleSudoku.c
Date: 11/03/12
OS: Windows 7 Enterprise x64, Intel i7, Code::Blocks 10.05
Description: This program prompts a user for an
----------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Constants
#define MAX_DIM 16
#define MAX_CHARS 101

//Prototype Declaration
/*1*/ FILE* openFile(char*,char*);
/*2*/ void assignArray(int puzzleArray[][MAX_DIM]);
/*3*/ int readArray(FILE*,int puzzleArray[][MAX_DIM]);
/*4*/ void playPuzzle(int puzzleArray[][MAX_DIM],int);
/*4a*/ void displayArray(int puzzleArray[][MAX_DIM], int);
/*5*/ bool userNum(int puzzleArray[][MAX_DIM],int);
/*5a*/ bool checkSolved(int puzzleArray[][MAX_DIM],int);
/*6*/ int validUsInput(int puzzleArray[][MAX_DIM],char,int,int,int);
void rewind( FILE *stream );


int main()
{

    //
    int puzzleArray[MAX_DIM][MAX_DIM];
    int size;
    FILE*sudoku;

    sudoku = openFile("Enter a filename (enter QUIT to end program): ", "r");
    while(sudoku!= NULL){
    assignArray(puzzleArray);
    size = readArray(sudoku,puzzleArray);
    playPuzzle(puzzleArray,size);
    sudoku = openFile("Enter a filename (enter QUIT to end program): ", "r");
    }
    return 0;
}

/*1*/ FILE* openFile(char*prompt,char*mode)
{
    FILE*fp;
    char filename[MAX_CHARS]="";

    fputs(prompt,stdout);
    gets(filename);
    if (strcmp(filename, "QUIT") == 0)
        return NULL;
    fp = fopen(filename, mode);
    return fp;
}

/*2*/ void assignArray(int puzzleArray[][MAX_DIM])
{
    int i;
    int j;

    for(i=0;i<MAX_DIM;i++){
        for(j=0;j<MAX_DIM;j++){
            puzzleArray[i][j] = -1;
            //printf("%d",puzzleArray[i][j]);
        }
    }
}

/*3*/ int readArray(FILE*input,int puzzleArray[][MAX_DIM])
{
    int i;
    int j;
    int size;
    int inputStr;
    char length[MAX_DIM];


    fgets(length,MAX_CHARS,input);
    size = strlen(length)/2;
    rewind(input);
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            fscanf(input,"%d",&puzzleArray[i][j]);
        }
    }
    return size;
}

/*4*/ void playPuzzle(int puzzleArray[][MAX_DIM],int size)
{
    char solve = false;
    char play = true;

    while(solve == false && play == true){
    displayArray(puzzleArray,size);
    play = userNum(puzzleArray,size);
    solve = checkSolved(puzzleArray,size);
    }

}

/*4a*/ void displayArray(int puzzleArray[][MAX_DIM], int size)
{
    int i;
    int j;
    int colNum=1;
    char space[1]={'\0'};
    char rowLet[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};

    printf("\n ");
    for(i=0;i<size;i++){
        printf("%4.1d",colNum);
        colNum++;
    }
    printf("\n  ");
    for(i=0;i<size;i++){
        printf("----");
    }
    printf("\n");
    for(i=0;i<size;i++){
        printf("%c", rowLet[i]);
        for(j=0;j<size;j++){
            if(puzzleArray[i][j]!=0)
                printf("%4.1d",puzzleArray[i][j]);
            if(puzzleArray[i][j]==0)
                printf("%4.1s",space);
        }
        printf("\n");
    }
    printf("\n");

}

/*5*/ bool userNum(int puzzleArray[][MAX_DIM],int size)
{
    char playPuzzle[MAX_CHARS];
    char userRowLet;
    int userColNum;
    int userValue;
    int code;
    int comp;
    int i=0;
    char rowLet[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
    int ch;

    printf("Would you like to place a number in the puzzle? (N or n for no): ");
    ch = getc(stdin);
    fflush(stdin);
    while(ch!=110 && ch!=32){
        fflush(stdin);
        printf("Enter a row letter: ");
        scanf("%c", &userRowLet);
        printf("Enter a column number: ");
        scanf("%d", &userColNum);
        printf("Enter int value to place (1 to %d): ",size);
        scanf("%d",&userValue);
        code = validUsInput(puzzleArray,userRowLet,userColNum,userValue,size);
        fflush(stdin);
        if(code== -1){ //Invalid Row
        printf("Invalid Row Letter, would you like to try again? (N or n for no): ");
        ch = getc(stdin);
        }
        if(code==(-2)){ //Invalid Column
        printf("Invalid Column Number, would you like to try again? (N or n for no): ");
        ch = getc(stdin);
        }
        if(code==(-3)){ //Value already exists in row/column
        printf("Value already exists in respective Row/Column, would you like to try again? (N or n for no): ");
        ch = getc(stdin);
        }
        if(code==(-4)){ //Value is out of range (not within the usable numbers)
        printf("Value does not exist in specified range, would you like to try again? (N or n for no): ");
        ch = getc(stdin);
        }
        if(code==0){
            while(userRowLet!=rowLet[i]){
                i++;
            }
            puzzleArray[i][userColNum-1] = userValue;
            fflush(stdin);
            return true;

        }
    }
    fflush(stdin);
    return false;
}

/*5a*/ bool checkSolved(int puzzleArray[][MAX_DIM],int size)
{
    int i;
    int j;
    int check;

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
        check = puzzleArray[i][j];
        if(check==0)
        return false;
        }
    }
    displayArray(puzzleArray,size);
    printf("\nYou solved it!\n\n");
    return true;
}

/*6*/ int validUsInput(int puzzleArray[][MAX_DIM],char userRowLet,int userColNum,int value, int size)
{
    int index=0;
    int j;
    int k;
    char rowLet[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};

    while(userRowLet!=rowLet[index]){
        index++;
    }
    if(index>=size)
    return (-1);
    if((userColNum>size)|| (userColNum<0))
    return (-2);
    for(j=0;j<size;j++){
        if(value==puzzleArray[index][j])
        return (-3);
        }
    for(k=0;k<size;k++){
        if(value==puzzleArray[k][userColNum-1])
        return (-3);
    }
    if((value>size)||(value<=0))
    return (-4);
    else
    return 0;
}




