#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *x;
    x = malloc(sizeof(int));
    int *y;
    //y = malloc(sizeof(int));
    *x = 42;
    y = x;
    *y = 13;
    printf("%i\n", *x);
}