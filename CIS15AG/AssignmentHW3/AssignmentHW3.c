//Evan Chen HW Assignment #3

//Header Files
#include <stdio.h>
#include <math.h>

//Defined constants for the unit prices and tax rate
#define TV 400.00;
#define VCR 220.00;
#define REMOTE 35.20;
#define CD 300.00;
#define RECORDER 150.00;
#define sales_tax 0.0825;

int main()

{
// Local Declaration
    double sub;
    double tax;
    double total;
    float tv;
    float vcr;
    float remote;
    float cd;
    float recorder;
    int a;
    int b;
    int c;
    int d;
    int e;

//Prompting User for Quantities Sold and storing value
    printf("How Many TVs Were Sold?");
    scanf("%d", &a);
    printf("How Many VCRs Were Sold?");
    scanf("%d", &b);
    printf("How Many Remote Controllers Were Sold?");
    scanf("%d", &c);
    printf("How Many CDs Were Sold?");
    scanf("%d", &d);
    printf("How Many Tape Recorders Were Sold?");
    scanf("%d", &e);

//Statements
tv=a*TV;
vcr=b*VCR;
remote=c*REMOTE;
cd=d*CD;
recorder=e*RECORDER;

sub= tv+vcr+remote+cd+recorder;
tax= sub*sales_tax;
total= sub+tax;

//Reading and printing values onto screen based off of the user's entered values
    printf("\nQTY\t      DESCRIPTION     UNIT PRICE       TOTAL PRICE\n");
    printf("\---\t      -----------     ----------       -----------\n");
    printf(" %d\t      TV                  400.00         %9.2f\n", a, tv);
    printf(" %d\t      VCR                 220.00         %9.2f\n", b, vcr);
    printf(" %d\t      REMOTE CTRLR         35.20         %9.2f\n", c, remote);
    printf(" %d\t      CD PLAYER           300.00         %9.2f\n", d, cd);
    printf(" %d\t      TAPE RECORDER       150.00         %9.2f\n", e, recorder);
    printf("                                           \t----------\n");
    printf("                           \tSUBTOTAL         %9.2f\n", sub);
    printf("                           \tTAX               %8.2f\n", tax);
    printf("                           \tTOTAL            %9.2f", total);
    return 0;

}
