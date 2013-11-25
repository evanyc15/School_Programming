//Evan Chen Lab Exercise #19

#include <stdio.h>
#include <stdlib.h>

void swap(int*,int*);
void bubble_sort(int a[],int size);
int search(int,int a[],int size);

int main()
{
    int i;
    int validity;
    int number;
    int stu_id[50];
    int size = sizeof(stu_id)/sizeof(int);

    FILE*fp;
    fp = fopen("C:/Users/echen4/Desktop/StudentID.txt", "r");
    if (!fp)
    {
        printf("Error, can't find file\n");
        exit(1);
    }

    for (i=0; i<50; i++)
    {
        fscanf(fp, "%d%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s", &stu_id[i]);
    }

    bubble_sort(stu_id,size);

    while(1)
    {
        printf("What student ID do you want to search for (0 to exit) ?\n");
        scanf("%d", &number);
        if(number == 0){
            break;
        }
        validity = search(number,stu_id,size);
        if (validity == -1){
            printf("%d is not a valid student ID\n\n", number);
        }
        else{
            printf("%d is a valid student ID\n\n",number);
        }
    }

    fclose(fp);
    return 0;
}

void bubble_sort (int a[], int size)
{
    int i,j;
    for (i = 0; i < size-2; i++){
        for (j = size-1; j > i; j--){
            if (a[j] < a[j-1]) swap(&a[j],&a[j-1]);
        }
    }
}


void swap(int*a,int*b)
{
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}

int search(int searchValue, int a[], int size)
{
    int low, high, middle;
    low = 0;
    high = size-1;
    while (low <= high){
        middle = (low + high) / 2;
        if (searchValue < a[middle]){
            high = middle - 1;
        }
        else if (searchValue > a[middle]){
            low = middle + 1;
        }
        else{
            return middle;
        }
    }
    return -1;
}
