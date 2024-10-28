#include <stdio.h>

int main(void)
{
    int times;
    printf("Enter number of times you want the cat to say meow: ");
    scanf("%d", &times);
    for (int i = 0; i < times; i++)
    {
        printf("meow!\n");
    }
}