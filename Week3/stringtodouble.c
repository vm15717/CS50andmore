#include <stdio.h>
#include <math.h>

double stod(char*);
double power(double, double);
int slen(char*);

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Please enter a number\n.");
    }
    double num = stod(argv[1]);
    printf("The number you have entered is %lf.\n", num);
}

double stod(char word[])
{
    int count = 0;
    double num;
    int len = slen(word);
    int dot = 0;
    while (word[count] != '\0')
    {
        if (word[count] == '.')
        {
            dot = 1;
        }
        if (dot == 0)
        {
            num += (word[count] - 48)*power(10, len - count - 1);
        }
        else if (dot > 0 && word[count] != '.')
        {
            num += (word[count] - 48)*power(10, -dot);
            dot++;
        }
        count++;
    }
    return num;   
}

double power(double val, double num)
{
    return exp(num * log(val));
}

int slen(char word[])
{
    int count = 0;
    while (word[count] != '.')
    {
        count++;
    }
    return count;
}