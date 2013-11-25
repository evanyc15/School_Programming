#include <stdio.h>
#include <math.h>

int main()

{
    float radius;
    const float PI=3.14;
    float area;

    printf("Evan Chen\n");
    printf("Programming Exercise #2\n");
    printf("Code:Blocks\n");
    printf("Enter the radius\n");
    scanf("%f", &radius);

    area=PI*radius*radius;

    printf("The area is: %f\n\n", area);
    return 0;

}
