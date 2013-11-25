//Evan Chen HW Assignment #6

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


//Prototypes
int roll();
void printName(int playerNo);
bool takeTurn(int playerNo,int*PlayerPoints);
void announceWinner(int playerNo, int points);
void printroll(int, int, int);
void printturn(int, int);



int main ()
{
//Statements
     srand(time(NULL));
     int player1Points = 0;
     int player2Points = 0;
     int player3Points = 0;
     bool gameOver = false;

     while (!gameOver)
     {
         gameOver = takeTurn(1, &player1Points);
         if(gameOver)
         break;
         gameOver = takeTurn(2, &player2Points);
         if(gameOver)
         break;
         gameOver = takeTurn(3, &player3Points);
         if(gameOver)
         break;
     }
}

//Function Declarations

//Return bool to end game
bool takeTurn(int playerNo, int*playerPoints)
{
    int x;
    int y;
    int turn;
    int a;
    bool stop;



    if (playerNo == 1)
        {
        printName(1);
        x = roll();
        y = roll();
            if (x > 1 && y > 1)
                {
                turn = x+y;
                *playerPoints += turn;
                printroll(x,y,turn);
                }
            else if (x == 1 && y == 1)
                {
                turn = 0;
                *playerPoints = 0;
                printroll(x,y,turn);
                }
            else
                {
                turn = 0;
                printroll(x,y,turn);
                }
        }
    if (playerNo == 2)
        {
        printName(2);
            for(a=0; a<2; a++)
            x = roll();
            y = roll();
                 if (x > 1 && y > 1)
                    {
                    turn = x+y;
                    *playerPoints += turn;
                    printroll(x,y,turn);
                    }
                else if (x == 1 && y == 1)
                    {
                    turn = 0;
                    *playerPoints = 0;
                    printroll(x,y,turn);
                    }
                else
                    {
                    turn = 0;
                    printroll(x,y,turn);
                    }
        }
    if (playerNo == 3)
        {
        printName(3);
            do
            {
            x = roll();
            y = roll();
                 if (x > 1 && y > 1)
                    {
                    turn = x+y;
                    *playerPoints += turn;
                    printroll(x,y,turn);
                    stop = false;
                    }
                else if (x == 1 && y == 1)
                    {
                    turn = 0;
                    *playerPoints = 0;
                    printroll(x,y,turn);
                    stop = true;
                    }
                else
                    {
                    turn = 0;
                    printroll(x,y,turn);
                    stop = true;
                    }
            }
            while(*playerPoints < 50 && !stop);
        }
    printturn(turn,*playerPoints);
    if (*playerPoints < 50)
        return false;
    else
        {
        announceWinner(playerNo, *playerPoints);
        return true;
        }
}

//Prints playername before their turn
void printName (int playerNo)
{
    if (playerNo == 1)
    printf("Joe, its your turn\n");
    if (playerNo == 2)
    printf("Mabel, its your turn\n");
    if (playerNo == 3)
    printf("Susan, its your turn\n");

}

//Announce the Winner of the game
void announceWinner(int playerNo, int points)
{
    if (playerNo == 1)
    printf("Joe won the game with %d points\n", points);
    if (playerNo == 2)
    printf("Mabel won the game with %d points\n", points);
    if (playerNo == 3)
    printf("Susan won the game with %d points\n", points);
}

//Prints the numbers rolled and its sum.
void printroll(int x, int y, int z)
{
    printf("    You rolled %d and %d. That's %d points\n", x,y,z);
}

//Prints total points for the turn and the player total points after roll.
void printturn(int x, int y)
{
    printf("  Points for the turn = %d. Total points = %d\n", x, y);
}

//Random roll of dice
int roll()
{
    return rand() % 6+1;
}
