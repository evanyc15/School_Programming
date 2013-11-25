#include <stdio.h>
#include <math.h>

int main()


{
//  Local Declarations
    int age;
    float half;

//  Statements
    printf("Evan Chen\n");
    printf("Lab Exercise #3\n");
    printf("Enter your age\n");
    scanf("%d", &age);

    half=age/2.0;

    printf("Your age is %d\n", age);
    printf("Half your age is $%4.2f", half);
    return 0;
}   //  main
