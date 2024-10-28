#include <stdio.h>

int main(void){
    long x;
    long y;
    printf("Enter the first number: ");
    scanf("%lu", &x);
    printf("Enter the second number: ");
    scanf("%lu", &y);
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x == y)
    {
        printf("x is equal to y\n");
    }
    else
    {
        printf("x is greater than y\n");
    }
}