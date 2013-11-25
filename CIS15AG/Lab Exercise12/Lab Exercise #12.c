//Evan Chen Lab Exercise #12
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>


int main ()
{
//Local Declarations
    srand(time(NULL));

    int heads = 0;
    int tails = 0;
    int x;
    int i;
    float percent_heads;
    float percent_tails;

//Statements
    for (i = 0; i < 1000000 ; i++)
    {
        x = rand() % 2 + 1;
        if (x == 1)
    {
            heads++;
    }
        else
            tails++;
    }

    percent_heads = (heads/1000000.00)*100;
    percent_tails = (tails/1000000.00)*100;


    printf("Number of heads = %d, percent = %2.2f\n", heads, percent_heads);
    printf("Number of tails = %d, percent = %2.2f\n", tails, percent_tails);
}


