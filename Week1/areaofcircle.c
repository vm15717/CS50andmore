#include <stdio.h>
#include <math.h>

int main(void){
    double radius = 0.0;
    double area;
    printf("Please enter the radius of a circle: ");
    scanf("%lf", &radius);
    area = M_PI*pow(radius,2);
    printf("The area of a circle with radius %lf is %lf\n", radius, area);
}