#include <stdio.h>

int main(void)
{
    char *s = "Hi!";
    printf("%p\n", s);
    printf("%c\n", *(s + 0));
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    printf("%c\n", *(s + 3));
    printf("%s\n", (s + 0));
    printf("%s\n", (s + 1));
    printf("%s\n", (s + 2));
    printf("%s\n", (s + 3));
}