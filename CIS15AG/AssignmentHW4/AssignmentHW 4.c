//Evan chen HW Assignement #4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototypes
float Random(float);
float deposit(float,float*);
float withdraw(float,float*);
float interest(float*);
void printHeading(void);

int main()
{
//Local Declarations
	float balance = 0.00;
	float amount;

//Statements
	srand(time(NULL));

	printHeading();

	amount = Random(1000.);
	deposit(amount, &balance);

	amount = Random(100.);
	withdraw(amount, &balance);

	interest(&balance);

	amount = Random(1000.);
	deposit(amount, &balance);

	amount = Random(1000.);
	withdraw(amount, &balance);

	amount = Random(100.);
	withdraw(amount, &balance);

	interest(&balance);

	amount = Random(100.);
	deposit(amount, &balance);

	amount = Random(100.);
	deposit(amount, &balance);

	amount = Random(1000.);
	withdraw(amount, &balance);
    return 0;

}

//Function Declarations
void printHeading(void)
{
        printf("Transaction\tAmount\tBalance\n");
        printf("-----------\t------\t-------\n");
}

float Random(float x)
{
    int y;
    y=100.*x;
    return (rand() % y)/100.00;
}

float deposit(float amount,float*balance)
{
    *balance +=amount;
    printf("Deposit\t\t%6.2f\t%7.2f\n",amount,*balance);
}

float withdraw(float amount,float*balance)
{
    *balance=*balance-amount;
    printf("Withdraw\t%6.2f\t%7.2f\n",amount,*balance);
}

float interest(float *y)
{
   float x=(*y*.003);
   *y +=x;
   printf("Interest\t%6.2f\t%7.2f\n", x,*y);
}


