//Evan Chen Makeup Assignment

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

int random_card();
int random_suite();

int main()
{
    srand(time(NULL));
    int i,j,k;
    int ra,su;
    int pairs = 0;
    int two_pairs = 0;
    int three_kind = 0;
    int full_house = 0;
    int four_kind = 0;
    int flushes = 0;
    int straights = 0;
    int str_flushes = 0;
    int royal_flushes = 0;
    int deck[52];
    int rank[5];
    int suit[5];
    char suites[4][10] = {"Spades", "Hearts", "Clubs", "Diamonds"};
    char card[13][10] = {"Ace","Two","Three","Four","Five",
                    "Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

    printf("\nHere's a poker hand\n");

//create deck
    for(i=0; i<52; i++){
            deck[i] = i;
            }

//shuffle
    for(i=0; i<52; i++){
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
        }

    for(i=0;i<5;i++){
        int x = rand()%52;
        int y = rand()%52;
        ra = deck[x]%13;
        su = deck[y]/13;
        printf("%s of %s\n", card[ra], suites[su]);
                    }
        printf("\n");

    for(i=0;i<1000000; i++){
            for(j=0;j<5;j++){
                    int x = random_card();
                    int y = random_suite();
                    rank[j]=deck[x]%13;
                    suit[j]=deck[x]/13;
                }

        bool swapped = false;
        do{
            swapped = false;
            for(k=0; k<4; k++){
                if(rank[k] > rank[k+1]){
                    int temp = rank[k];
                    rank[k] = rank[k+1];
                    rank[k+1] = temp;
                    swapped = true;
                        }}}
                while(swapped == true);

        //Royal Flush
        if(rank[0]==1 && rank[1]==9 && rank[2]==10 && rank[3]==11 && rank[4]==12
           &&suit[0]==suit[1] && suit[1]==suit[2] && suit[2]==suit[3] && suit[3]==suit[4])
            royal_flushes++;
        //Straight Flush
        if(rank[0]==rank[1]-1 && rank[1]==rank[2]-1 && rank[2]==rank[3]-1 && rank[3]==rank[4]-1
           &&suit[0]==suit[1] && suit[1]==suit[2] && suit[2]==suit[3] && suit[3]==suit[4])
            str_flushes++;
        //Straight
        if(rank[0]+1==rank[1] && rank[1]+1==rank[2] && rank[2]+1==rank[3] && rank[3]+1==rank[4]
           || rank[0]==1 && rank[1]==10 && rank[2]==11 && rank[3]==12 && rank[4]==13)
            straights++;
        //Flush
        if(suit[0]==suit[1] && suit[1]==suit[2] && suit[2]==suit[3] && suit[3]==suit[4])
            flushes++;
       //Four of a kind
        if(rank[0]==rank[1] && rank[1]==rank[2] && rank[2]==rank[3]
           || rank[1]==rank[2] && rank[2]==rank[3] && rank[3]==rank[4])
            four_kind++;
        //Full House
        if(rank[0]==rank[1] && rank[1]==rank[2] && rank[3]==rank[4]
           || rank[0]==rank[1] && rank[2]==rank[3] && rank[3]==rank[4])
            full_house++;
        //Three of a kind
        if(rank[0]==rank[1] && rank[1]==rank[2] || rank[1]==rank[2] && rank[2]==rank[3]
            || rank[2]==rank[3] && rank[3]==rank[4])
            three_kind++;
        //Two Pairs
        if(rank[0]==rank[1] && rank[2]==rank[3] || rank[1]==rank[2] && rank[3]==rank[4])
            two_pairs++;
        //Pairs
        if(rank[0]==rank[1] || rank[1]==rank[2] || rank[2]==rank[3] || rank[3]==rank[4])
            pairs++;

        }

    printf("Number of pairs = %d\n", pairs);
    printf("Number of two pairs = %d\n", two_pairs);
    printf("Number of three of a kind = %d\n",three_kind);
    printf("Number of full houses = %d\n", full_house);
    printf("Number of four of a kind = %d\n",four_kind);
    printf("Number of flushes = %d\n", flushes);
    printf("Number of straights = %d\n", straights);
    printf("Number of straight flushes = %d\n",str_flushes);
    printf("Number of royal flushes = %d\n", royal_flushes);

    return 0;
}

int random_card()
{
    int x = rand()%52;
    return x;
}

int random_suite()
{
    int x = rand()%52;
    return x;
}
