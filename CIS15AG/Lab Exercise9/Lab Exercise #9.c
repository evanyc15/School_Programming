//Evan Chen Lab Exercise #9

#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

//Prototypes
double random(double*);


int main()
{
//Local Declarations
    double f = 10.00;

//Statements
    printf("%.2f\n",random(&f));
    printf("%.2f\n",random(&f));
    printf("%.2f\n",random(&f));
    printf("%.2f\n",random(&f));
    printf("%.2f\n",random(&f));
    printf("%.2f\n",random(&f));
    printf("%.2f\n",random(&f));
    printf("%.2f\n",random(&f));
    printf("%.2f\n",random(&f));
    return 0;
}

//Function Declarations
double random(double*num)
{
    double rand_double;
    double rand_number;
    double x= *num;

    rand_double = rand() % RAND_MAX;
    rand_number = rand_double/RAND_MAX;
    return (rand_number*x);
}

