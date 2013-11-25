//Evan Chen Lab Exercise #14

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


//Prototypes
int roll();
bool rollDice(int*);
void printout(int, int);


int main()
{
//Statements
    srand(time(NULL));
    int total = 0;
    int sum;
    int x;
    int y;


    FILE* fp;
    fp = fopen ("C:/Users/echen4/Desktop/Lab Assignment #14.txt", "w");
    if (fp == 0)
   {
       fprintf(stderr, "Can't find file.\n");
       exit(1);
   }


    while (total < 101)
    {
        x = rand() % 6+1;
        y = rand() % 6+1;
        sum = x + y;
        total += sum;

        fprintf(fp, "%10d%10d\n", sum, total);
    }

}
