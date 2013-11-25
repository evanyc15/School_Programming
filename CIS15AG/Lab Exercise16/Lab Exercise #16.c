//Evan Chen Lab Exercise #16

#include <stdio.h>

int main (void)
{
    FILE* fp;
    FILE* out;
    int scanned = 0;
    float gain;
    float openingprice = 0;
    float closingprice = 0;
    float sumclosingprice = 0;
    int numMarketDays = 0;

    fp = fopen("C:/Users/echen4/Desktop/APPLEdata.txt","r");
    out= fopen("C:/Users/echen4/Desktop/Lab16output.txt", "w");

    if (!fp || !out)
    {
        printf("Error opening file");
        return (1);
    }

    fprintf(out, "      Open     Close      Gain\n");

    while (scanned != EOF)
    {
        if (fscanf(fp,"%*s%f%*s%*s%*s%*s%f",&openingprice, &closingprice)==2)
        {
            gain = closingprice - openingprice;
            fprintf(out, "%10.2f%10.2f%10.2f\n",openingprice,closingprice,gain);
        }
        else
            break;
    }

    fclose(fp);
    fclose(out);
    return 0;
}
