#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char s[20];
    printf("Enter a word: ");
    fgets(s, sizeof(s), stdin);
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (s[i] >= 'a' && s[i] <='z')
        {
            printf("%c", s[i]-32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < length; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}