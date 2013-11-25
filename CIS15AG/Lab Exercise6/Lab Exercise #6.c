//Evan Chen Lab Exercise #6

#include <stdio.h>

int main()
{
    double areaOfTriangle(double base, double height);
    double base, height, area;
    printf("Enter the base and height => ");
    scanf("%lf%lf",&base,&height);

    area = areaOfTriangle(base,height);

    printf("The area is %10.2f\n", area);
    return 0;

}

    double areaOfTriangle(double b, double h)
{
    double area;
    area= 0.5 * b * h;
    return area;
}
