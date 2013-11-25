//Evan Chen Lab Exercise #10
#include <stdio.h>

//Prototype
void printGrade(int);

int main()
{
    printGrade(-1);
    printGrade(55);
    printGrade(65);
    printGrade(75);
    printGrade(85);
    printGrade(95);
    printGrade(105);
    return 0;
}

//Function Declaration
void printGrade(int score)
{

    if (score >=100 || score <=0)
        printf("Invalid percent\n");
    else if(score >= 90)
        printf("A\n");
    else if (score >= 80)
        printf("B\n");
    else if (score >= 70)
        printf("C\n");
    else if (score >= 60)
        printf("D\n");
    else
        printf("F\n");

    return;
}
