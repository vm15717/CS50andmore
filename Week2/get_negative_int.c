#include <stdio.h>

int get_negative_int(void);

int main(void)
{
    int n = get_negative_int();
    printf("The negative integer is %i\n", n);
}

int get_negative_int(void)
{
    int n;
    do
    {
        printf("Please enter a negative Integer: ");
        scanf("%i", &n);
    } while (n < 0);
    return n;
}