//Evan Chen Lab Exercise #7

#include <stdio.h>

//Prototypes
int incrementByValue(int);
int incrementByReference(int*x);

int main()
{
    int i = 1, j = 1;
    printf("Before the call to incrementByValue(): i = %d\n",i);
    incrementByValue(i);
    printf("After the call to incrementByValue(): i = %d\n",i);

    printf("Before the call to incrementByReference(): j = %d\n",j);
    incrementByReference(&j);    // you figure it out
    printf("After the call to incrementByReference(): j = %d\n",j);
    return 0;
}

//Function Declaration
int incrementByValue(int x)
{
    printf("Inside incrementByValue():%d\n", ++x);

}

int incrementByReference(int*x)
{
    printf("Inside incrementByReference(): %d\n", *x +=1);
}
