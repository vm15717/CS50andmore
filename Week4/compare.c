#include <stdio.h>

int main(void)
{
    int i;
    int j;
    printf("i: ");
    scanf("%i", &i);
    printf("j: ");
    scanf("%i", &j);
    if (i == j)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}