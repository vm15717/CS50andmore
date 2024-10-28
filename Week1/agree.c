#include <stdio.h>

int main(void)
{
    char c;
    printf("Do you agree?: ");
    scanf("%c", &c);
    if (c == 'Y' || c == 'y') // double quotes for strings. single quotes for chars.
    {
        printf("Agreed\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not Agreed\n");
    }
    else
    {
        printf("Not a valid character\n");
    }
}