#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *scores = malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i++)
    {
        printf("%i\n", scores[i]);
    }
    free(scores);
}