#include <stdio.h>
#include <math.h>

int main(void){
    double x;
    double sigmoid;
    printf("Enter a number: ");
    scanf("%lf", &x);
    sigmoid = 1/(1+exp(-x));
    printf("The sigmoid of %lf is %lf\n", x, sigmoid);
}