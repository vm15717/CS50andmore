#include <stdio.h>

int main(void)
{
    long x;
    long y;
    printf("Enter the first number: ");
    scanf("%lu", &x);
    printf("Enter the second number: ");
    scanf("%lu", &y);
    double z = (double) x/ (double) y;
    printf("The answer is %.20f\n", z);
}