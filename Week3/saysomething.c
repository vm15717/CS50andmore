#include <stdio.h>

int charlen(char*);
void print_pattern(int);
void print_smiley(int);
int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Please enter a word!\n");
    }
    print_pattern(charlen(argv[1]));
    printf("%s\n", argv[1]);
    print_pattern(charlen(argv[1]));
}

int charlen(char a[])
{
    int count = 0;
    while(a[count] != '\0')
    {
        count++;
    }
    return count;
}

void print_pattern(int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("-");
    }
    printf("\n");
}