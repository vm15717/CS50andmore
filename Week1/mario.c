#include <stdio.h>

int main(void)
{
    int size;
    for (int i = 0; i < 4; i++)
    {
        printf("?");
    }
    printf("\n");
    do // Specific to C. cleanest way. Doesnt exist in other languages
    {
        printf("Enter the size of the grid: ");
        scanf("%d", &size);
    }
    while (size < 1);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}