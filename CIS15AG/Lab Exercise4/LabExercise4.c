//Evan Chen Lab Exercise #4

#include <stdio.h>
#include <math.h>

int main ()

{
    int a;
    int b;
    int c;
    double d;

    printf("Enter two ints\n");
    scanf("%d %d", &a,&b);

    a+=1;
    c=a*b;
    d=1.0*a/b;

    printf("%10d%10d%10d%10.2f", a, b, c, d);
    return 0;
}
