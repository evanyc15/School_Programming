//Evan Chen HW Assignment #8
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
    long int id[50];
    int as1[50];
    int as2[50];
    int as3[50];
    int as4[50];
    int as5[50];
    int as6[50];
    int as7[50];
    int as8[50];
    int mid[50];
    int fin[50];
    int cl[50];
    int le[50];
    float perc[50];
    int letter_A = 0;
    int letter_B = 0;
    int letter_C = 0;
    int letter_D = 0;
    int letter_F = 0;
    int average_total = 0;
    int average_percent = 0;
    float median;
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

//Statements
    FILE*wr;
    FILE*rv;
    FILE*sr;
    wr = fopen ("/Users/evanchen/Desktop/Assign8Output.txt", "w");
    rv = fopen ("/Users/evanchen/Desktop/ReadValue8.txt", "r");
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
    fscanf(rv, "%ld %d %d %d %d %d %d %d %d %d %d %d %d",&id[x],&as1[x],&as2[x],&as3[x],
                &as4[x],&as5[x],&as6[x],&as7[x],&as8[x],&mid[x],&fin[x],&cl[x],&le[x]);

    lowest = as1[x];
    if (lowest > as2[x])
    lowest = as2[x];
    if (lowest > as3[x])
    lowest = as3[x];
    if (lowest > as4[x])
    lowest = as4[x];
    if (lowest > as5[x])
    lowest = as5[x];
    if (lowest > as6[x])
    lowest = as6[x];
    if (lowest > as7[x])
    lowest = as7[x];
    lowest_assign = lowest;

    total_assign = (as1[x]+as2[x]+as3[x]+as4[x]+as5[x]+as6[x]+as7[x]+as8[x])-lowest_assign;
    total = total_assign+(mid[x]+fin[x]+le[x]+cl[x]);
    percent = ((float)total/possiblePTS)*100;
    overall = round(percent);
    perc[x] = overall;
    rem = ((int)overall)%10;
    grade = overall/10;

    average_total += total;
    average_percent += overall;

    if (overall == 100){
        letter = 'A';
        }
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
                break;
            default: letter = 'F';
                    letter_F++;
                    break;
                    }
    }

    fprintf(wr, "%08ld %3d %2d %2d %2d %2d %2d %2d %2d %4d %3d %4d %3d %3d %5d %4.0f %c\n",id[x],
                                    as1[x],as2[x],as3[x],as4[x],as5[x],as6[x],as7[x],as8[x],
                                    total_assign-lowest_assign, mid[x],fin[x],cl[x],le[x],total,
                                    perc[x],letter);
    }

    atotal = average_total/50.0;
    apercent = average_percent/50.0;
//Part 2, print to file

    median = (perc[24] + perc[25])/2;

    fprintf(sr, "The median percent total = %2.1f\n", median);
    fprintf(sr, "The average total points = %.0f\n", atotal);
    fprintf(sr, "The average percent total = %.0f\n", apercent);
    fprintf(sr, "The number of A's = %d\n",letter_A);
    fprintf(sr, "The number of B's = %d\n",letter_B);
    fprintf(sr, "The number of C's = %d\n",letter_C);
    fprintf(sr, "The number of D's = %d\n",letter_D);
    fprintf(sr, "The number of F's = %d\n",letter_F);

return 0;
}

