#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char *s = malloc(sizeof(char) * 30);
    printf("s: ");
    fgets(s, sizeof(s), stdin);
    if (s == NULL) // NULL returned my malloc. Need to do this in practice.
    {
        return 1;
    }
    int stlen = strlen(s);
    char *t = malloc(sizeof(char) * stlen + 1);
    if (t == NULL)
    {
        return 2;
    }
    for (int i = 0; i < stlen + 1; i++)
    {
        t[i] = s[i]; // need the null character so strlen(s) + 1
    }
    t[0] = toupper(t[0]);
    printf("%s", s);
    printf("%s", t);
    free(s);
    free(t); // lets the computer know that we are done with the memory.
    return 0;
}