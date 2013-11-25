//Evan Chen Lab Exercise #20

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
   // float daily_gain;
    float op;
    int ct;
    int ch;
    float adjclose;
   // float daily_pergain;
  //  float dpg_sum = 0;
  //  float average;
   // char temp[200];
    FILE*fp;
   // int temp2;

    fp = fopen("C:/Users/echen4/Desktop/applestocks2.txt", "r");
    if(!fp)
    {
        printf("Can't find file\n");
        exit(1);
    }
for (i = 0; i < 50; i++)
{
    ch = getc(fp);
    printf("%c %d\n", ch);
}
   // for(i=0;i<5;i++)
   // {
        ct =fscanf(fp, "%*s %f %*s %*s %*s %*s %f", &op,&adjclose);
        printf("%d  %f\t%f\n",ct,op, adjclose);
        //daily_gain = adjclose - open;
        //daily_pergain = (daily_gain/open)*100.00;
        //dpg_sum += daily_pergain;
   // }

   // average = dpg_sum/500.00;

   // printf("The average daily percent gain of Apple stock over the last\n");
   // printf("500 market days is %4.2f%c\n",average,'%');

    fclose(fp);
    return 0;
}
