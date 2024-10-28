#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    int **q = &p;
    printf("The address of %i is %p.\n", n, p);
    printf("The value at address of %p is %p.\n", q, *q);
    printf("The value is %i\n", **q);
}