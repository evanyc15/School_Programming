//Evan Chen Lab Exercise #17

#include <stdio.h>

int main()
{
    float adjclose[50];
    int i;
    float sum = 0;
    float average;

    FILE*fp;
    fp = fopen("C:/Users/echen4/Desktop/Data7.txt", "r");

    if (!fp)
    {
        printf("Error opening file");
        return (1);
    }

    for (i=0; i<50; i++)
    {
        fscanf(fp, "%*s%*s%*s%*s%*s%*s%f", &adjclose[i]);
        sum += adjclose[i];
    }

    average = sum/50.0;
    printf("The average is $%5.2f", average);

    fclose(fp);
    return 0;
}


//Output
//The average is $12769.55
