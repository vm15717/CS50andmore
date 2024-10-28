#include <stdio.h>

int convert_to_decimal(char*, char*);
int power(int, int);
int char_len(char*);

int main(int argc, char **argv)
{
    int decimal_num = convert_to_decimal(argv[1], argv[2]);
    printf("The decimal number corresponding to %s in base %s is %i.\n", argv[1], argv[2], decimal_num);
    return 0;
}

int convert_to_decimal(char *num, char *base)
{
    int count = 0;
    int number = 0;
    int base2 = *base - 48;
    int charlen = char_len(num);
    while (*(num + count) != '\0')
    {
        number += power(base2, charlen - count - 1) * (*(num + count) - 48);
        count++;
    }
    return number;
}


int power(int num, int pow)
{
    int prod = 1;
    for (int i = 0; i < pow; i++)
    {
        prod *= num;
    }
    return prod;
}

int char_len(char *num)
{
    int count = 0;
    while (*(num + count) != '\0')
    {
        count++;
    }
    return count;
}

char* convert_to_base(int num)
{
    
}