//Evan Chen HW Assignment #5

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Memory Constants
#define POSSIBLEPTS 500
#define ASSIGNMENT 25
#define MIDTERM 75
#define FINAL 150
#define CODELAB 40
#define LAB 60

//Prototypes
void read_value(int*, int);
void exit (int terminationStatus);
void grade(int,int,int,int,int,int,int,int,int,int,int,int);
void grade_letter(int);


int main()
{

//Local Declarations
    int assign1 = 0;
    int assign2 = 0;
    int assign3 = 0;
    int assign4 = 0;
    int assign5 = 0;
    int assign6 = 0;
    int assign7 = 0;
    int assign8 = 0;
    int midterm = 0;
    int final = 0;
    int lab = 0;
    int code= 0;

//Statements
    printf("Enter 8 assignment grades one at a time\n");

//Assignments
    read_value(&assign1,ASSIGNMENT);
    read_value(&assign2,ASSIGNMENT);
    read_value(&assign3,ASSIGNMENT);
    read_value(&assign4,ASSIGNMENT);
    read_value(&assign5,ASSIGNMENT);
    read_value(&assign6,ASSIGNMENT);
    read_value(&assign7,ASSIGNMENT);
    read_value(&assign8,ASSIGNMENT);

//Midterm
    printf("Enter midterm grade => ");
    read_value(&midterm,MIDTERM);
//Final
    printf("Enter final grade => ");
    read_value(&final,FINAL);
//Lab Exercises
    printf("Enter Lab Exercise Points => ");
    read_value(&lab,LAB);
//CodeLab
    printf("Enter CodeLab points => ");
    read_value(&code,CODELAB);

    grade(assign1,assign2,assign3,assign4,assign5,assign6,assign7,assign8,
          midterm,final,lab,code);

    return 0;
}

/*Reads the value inputted by user and makes sure it does not exceed max amounts of points or
go under 0*/
void read_value(int*user, int max)
{
    int value;
    printf(" ->");
    scanf("%d", &value);

    if (value > max || value < 0)
        {
        printf("Invalid Point: %d maximum allowed is %d\nTry again. Enter point ->", value,max);
        scanf("%d", &value);

        if (value <= max && value >= 0)
            printf("That's  better\n");

        if (value > max || value < 0)
            {
            printf("You did it again. I quit.\n");
            exit (1);
            }
        }
    else
    printf("Thanks\n");

    *user = value;
    return;
}

/*Prints grades and calculates the total points, percentage, and Grade letter*/
void grade(int as1,int as2,int as3,int as4,int as5,int as6,int as7,int as8,int midterm,int final,
           int lab,int code)
{

//Local Declaration
int total_assign;
int total;
float overall;
int lowest;
float percent;

//Determining lowest scored assignment
int lowest_assign = as1;
if (lowest_assign > as2)
lowest_assign = as2;
if (lowest_assign > as3)
lowest_assign = as3;
if (lowest_assign > as4)
lowest_assign = as4;
if (lowest_assign > as5)
lowest_assign = as5;
if (lowest_assign > as6)
lowest_assign = as6;
if (lowest_assign > as7)
lowest_assign = as7;
lowest = lowest_assign;

    total_assign=as1+as2+as3+as4+as5+as6+as7+as8;
    total= total_assign+midterm+final+lab+code-lowest;
    percent = ((float)total/POSSIBLEPTS)*100;
    overall = round(percent);

//Prints Grades
    printf("\n\nAssignment Grades: %7d%7d%7d%7d%7d%7d%7d%7d\n",as1,as2,as3,as4,as5,as6,as7,as8);
    printf("Midterm:\t%d\n",midterm);
    printf("Final:%4d\n", final);
    printf("Lab Exercises:\t%d\n",lab);
    printf("CodeLab:\t%d\n",code);

    printf("Total Points:\t%d\n", total);
    printf("Percent of total points:%4.0f\n", overall);
    grade_letter(overall);
}

void grade_letter(int x)
{
    int rem = x % 10;
    int grade = x/10;
    char letter;
    char sign;

    //Calculate 100% as A+
    if (x == 100)
    {
        letter = 'A';
        sign = '+';
    }
    //Prevent signs for F
    else if (x < 60)
    {
        letter = 'F';
        sign = ' ';
    }
    else
        {
            switch(grade)
            {
            case 9: letter = 'A';
                    break;
            case 8: letter = 'B';
                    break;
            case 7: letter = 'C';
                    break;
            case 6: letter = 'D';
                    break;
            }
            switch (rem)
            {
            case 9: sign = '+';
                    break;
            case 0: sign = '-';
                    break;
            default: sign = ' ';
            }
        }

    printf("Grade:\t%c%c\n", letter,sign);
}
