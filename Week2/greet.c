#include <stdio.h>

int main(int argc, char** argv)
{
    char name[20];
    if (argc == 2)
    {
        printf("Hello, %s\n", argv[1]);
    }
    else
    {
        printf("Hello, World!\n");
    }
}