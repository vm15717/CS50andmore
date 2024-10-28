#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(sizeof(int) * 3);
    if (x == NULL)
    {
        return 1;
    }
    x[0] = 1;
    x[2] = 79;
    x[3] = 100;
    free(x);
    return 0;
}