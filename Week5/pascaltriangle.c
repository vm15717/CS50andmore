#include <stdio.h>
#include <math.h>
#include <string.h>

int chartoint(char *);
void print_pascal(int);
int choose(int, int);
int factorial(int);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Please enter the number of rows!.\n");
    }
    int num = chartoint(argv[1]);
    printf("The number is %i\n", num);
    print_pascal(num * 2);
}

int chartoint(char *word)
{
    int num = 0;
    int count = 0;
    int len = strlen(word);
    while (word[count] != 0)
    {
        num += pow(10, len - count - 1) * (word[count] - 48);
        count++;
    }   
    return num;
}

void print_pascal(int nrows)
{
    int k = 0;
    for (int i = 0; i < nrows/2; i++)
    {   
        k = 0;
        for (int j = 0; j < nrows ; j++)
        {
            if ( j < nrows/2 - i)
            {
                printf(" ");
            }
            else if (j > nrows/2 + i)
            {
                printf(" ");
            }
            else
            {
                if ((j + i) % 2 == 1)
                {
                    printf("%i", choose(i, k));
                    k++;
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int choose(int i, int k)
{
    return factorial(i)/(factorial(i - k) * factorial(k));
}

int factorial(int i)
{
    if (i == 0)
    {
        return 1;
    }
    else
    {
        return i * factorial(i - 1);
    }
}