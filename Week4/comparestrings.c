#include <stdio.h>

int main(void)
{
    char s[20];
    char t[20];
    fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);
    if (s == t)
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }
}