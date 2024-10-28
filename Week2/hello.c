#include <stdio.h>

int main(void)
{
    char name[20];
    printf("Please give your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Hello, %s\n", name);
}
