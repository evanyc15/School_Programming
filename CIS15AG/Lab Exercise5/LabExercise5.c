//Evan Chen Lab Exercise #5

#include <stdio.h>
#include <math.h>

int main()

{
//Local Declarations
    float length;
    float width;
    float Area;
    float Perimeter;

//Statements
    printf("Please enter length and width\n");
    scanf("%f %f", &length, &width);

    Area= length*width;
    Perimeter= 2*length+2*width;

    printf("The Area is %5.2f\n", Area);
    printf("The Perimter is %7.4f\n", Perimeter);
    return 0;

}
