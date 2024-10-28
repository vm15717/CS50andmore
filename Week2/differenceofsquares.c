#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int difference(int);
int chartoint(char*);
int charlen(char*);

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Please enter a number!\n");
        return -1;
    }
    int num = chartoint(argv[1]);
    printf("The number is %i.\n", num);
    int ans = difference(num);
    printf("The difference between square of sum and the sum of squares for the first %i integers is %i.\n", num, ans);
}

int chartoint(char a[])
{
    int count = 0;
    int len = charlen(a);
    int num;
    while(a[count] != '\0')
    {
        num += (a[count] - 48) * pow(10, len - count - 1);
        count++;
    }
    return num;
}
int difference(int num)
{
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 1; i < num + 1; i++)
    {
        sum1 += i;
        sum2 += pow(i, 2);
    }
    return pow(sum1, 2) - sum2;
}

int charlen(char word[])
{
    int count = 0;
    while(word[count] != '\0')
    {
        count++;
    }
    return count;
}