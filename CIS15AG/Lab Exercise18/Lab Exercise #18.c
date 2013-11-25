//Evan Chen Lab Exercise #18

#include <stdio.h>

void bubble_sort(float a[], int size);
void swap(float*a,float*b);

int main()
{

    int i;
    float adjclose[50];
    int size = sizeof(adjclose)/sizeof(int);

    FILE*fp;
    fp = fopen("C:/Users/echen4/Desktop/Dow Jones.txt", "r");

    if (!fp)
    {
        printf("Error, Can't find file\n");
        exit(1);
    }

    for (i=0; i<50; i++)
        {
            fscanf(fp, "%*s%*s%*s%*s%*s%*s%f", &adjclose[i]);
        }

    bubble_sort(adjclose, size);

    printf("The minimum adjusted close of the Dow Jones Industrial Average for the last 50 market days is %5.2f\n", adjclose[0]);
    printf("The maximum adjusted close of the Dow Jones Industrial Average for the last 50 market days is %5.2f\n", adjclose[49]);

    fclose(fp);
    return 0;

}

void bubble_sort(float a[], int size)
{
    int i,j;
    for(i=0;i<size-2;i++)
    {
        for(j=size-1;j>i;j--)
        {
            if(a[j]<a[j-1]) swap(&a[j],&a[j-1]);
        }
    }
}

void swap (float*a,float*b)
{
    float temp;
    temp = *a;
    *a=*b;
    *b=temp;
}


/*Output
The minimum adjusted close of the Dow Jones Industrial Average for the last 50
market days is 12359.92
The maximum adjusted close of the Dow Jones Industrial Average for the last 50
market days is 13252.76*/
