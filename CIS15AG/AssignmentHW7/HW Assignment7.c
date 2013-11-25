//Evan Chen HW Assignment #7

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Memory Constants
#define possiblePTS 500

int main()
{
//Function Declaration
    int x,i,j;
    long int id;
    int as1,as2,as3,as4,as5,as6,as7,as8;
    int mid,fin,cla,lex;
    int letter_A = 0;
    int letter_B = 0;
    int letter_C = 0;
    int letter_D = 0;
    int letter_F = 0;
    int average_total = 0;
    int average_percent = 0;
    int lowest;
    int lowest_assign;
    int total_assign;
    int total;
    int grade;
    int rem;
    float atotal;
    float apercent;
    float overall;
    float percent;
    char letter;
    char sign;

//Statements
    FILE*wr;
    FILE*rv;
    FILE*sr;
    wr = fopen ("/Users/evanchen/Desktop/Assign7Output.txt", "w");
    rv = fopen ("/Users/evanchen/Desktop/Readvalue.txt", "r");
    sr = fopen ("/Users/evanchen/Desktop/SummaryReport.txt", "w");
//Checks if file opens
    if (wr == 0 || rv == 0 || sr == 0){
       fprintf(stderr, "Can't find file.\n");
       exit(1);
   }

//Prints Output file
    fprintf(wr, "Student   --- Asignment Grades --  Ass Mid  Fin CLa LEx Total  Pct Gr\n");
    fprintf(wr, "--------  -- -- -- -- -- -- -- --  --- ---  --- --- --- -----  --- --\n");
//Scans Students Grades and prints to a file
    for (x = 0; x<50; x++){
    fscanf(rv, "%ld %d %d %d %d %d %d %d %d %d %d %d %d",&id,&as1,&as2,&as3,&as4,&as5,&as6,&as7,&as8,&mid,&fin,&cla,&lex);

    lowest = as1;
    if (lowest > as2)
    lowest = as2;
    if (lowest > as3)
    lowest = as3;
    if (lowest > as4)
    lowest = as4;
    if (lowest > as5)
    lowest = as5;
    if (lowest > as6)
    lowest = as6;
    if (lowest > as7)
    lowest = as7;
    lowest_assign = lowest;

    total_assign = (as1+as2+as3+as4+as5+as6+as7+as8)-lowest_assign;
    total = total_assign+mid+fin+lex+cla;
    percent = ((float)total/possiblePTS)*100;
    overall = round(percent);
    rem = ((int)overall)%10;
    grade = overall/10;

    average_total += total;
    average_percent += overall;

    if (overall == 100){
        letter = 'A';
        sign = '+';}
    else if (overall < 60){
        letter = 'F';
        sign = ' ';
        letter_F++;}
    else{
        switch(grade){
            case 9: letter = 'A';
                    letter_A++;
                break;
            case 8: letter = 'B';
                    letter_B++;
                break;
            case 7: letter = 'C';
                    letter_C++;
                break;
            case 6: letter = 'D';
                    letter_D++;
                break;}
        switch (rem){
            case 9: sign = '+';
                break;
            case 0: sign = '-';
            default: sign = ' ';}

    }
    fprintf(wr, "%08ld %3d %2d %2d %2d %2d %2d %2d %2d %4d %3d %4d %3d %3d %5d %4.0f %c%c\n",id,as1,as2,as3,
                                    as4,as5,as6,as7,as8,total_assign-lowest_assign,
                                    mid,fin,cla,lex,total,overall,letter,sign);
    }

    atotal = average_total/50.0;
    apercent = average_percent/50.0;
//Part 2, print to file
    fprintf(sr, "The average total points = %.0f\n", atotal);
    fprintf(sr, "The average percent total = %.0f\n", apercent);
    fprintf(sr, "The number of A's = %d\n",letter_A);
    fprintf(sr, "The number of B's = %d\n",letter_B);
    fprintf(sr, "The number of C's = %d\n",letter_C);
    fprintf(sr, "The number of D's = %d\n",letter_D);
    fprintf(sr, "The number of F's = %d\n",letter_F);

return 0;
}
