//Evan Chen Lab Exercise #8

#include <stdio.h>

//Prototypes
int rotate3(int*,int*,int*);

int main()
{
//Local Declaration
    int i = 1, j = 2, k = 3;

//Statements
    printf("Before 1st call to rotate3(): %d %d %d\n", i,j,k);
    rotate3(&i,&j,&k);        // you figure it out
    printf("After 1st call to rotate3(): %d %d %d\n", i,j,k);
    rotate3(&i,&j,&k);
    printf("After 2nd call to rotate3(): %d %d %d\n", i,j,k);
    rotate3(&i,&j,&k);
    printf("After 3rd call to rotate3(): %d %d %d\n", i,j,k);
    return 0;
}


//Function Declarations
int rotate3(int*x,int*y,int*z)
{
    int t=*x;
    *x=*y;
    *y=*z;
    *z=t;
}


