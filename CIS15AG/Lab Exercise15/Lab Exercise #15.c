//Evan Chen Lab Exercise #15

#include <stdio.h>
#include <stdlib.h>

#define NUMBERS 50.00

int main()
{
    int i;
    int j;
    int final;
    int sum = 0;
    float total;
    float average;

    FILE*fp;
    fp = fopen ("C:/Users/echen4/Desktop/LabEx#5 Read.txt", "r");
    if (fp == 0)
    {
        fprintf(stderr, "Can't find file.\n");
        exit (1);
    }

    for (i = 0; i < 50; i++){
        for (j = 1 ; j <= 13; j++)
        {
        fscanf(fp,"%d", &final);
    if (j == 11)
        sum = sum + final;
        }
    }

total = (float)sum;
average = total/NUMBERS;

printf("The average final grade is %10.6f\n", average);

return 0;
}

