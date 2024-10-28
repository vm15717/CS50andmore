#include <stdio.h>
#include <math.h>

float chartofloat(char*);
float squareroot(float);
int charlen(char*);
float absol(float);

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Please enter a number.\n");
        return -1;
    }
    float num = chartofloat(argv[1]);
    printf("%f\n", num);
    float sqnum = squareroot(num);
}

float chartofloat(char a[])
{
    int count = 0;
    int len = charlen(a);
    float num;
    int dot = 0;
    while(a[count] != '\0')
    {
        if (a[count] == '.')
        {
            dot = 1;
        }
        if (dot == 0)
        {
            num += (a[count] - 48)*pow(10, len - count - 1);
        }
        else if (dot > 0 && a[count] != '.')
        {
            num += (a[count] - 48)*pow(10, -dot);
            dot++;       
        }
        count ++;
    }
    return num;
}

int charlen(char a[])
{
    int count = 0;
    while(a[count] != '.')
    {
        count++;
    }
    return count;
}

float squareroot(float num)
{
    float err = 100;
    float start = num/2;
    int iter = 0;
    do
    {
        start = start - ((pow(start, 2) - num) / (2*start));
        printf("%f\n", start);
        err = absol(pow(start, 2) - num);
        iter++;
    } while (err > 0.000005 && iter < 1000);
    return start;   
}

float absol(float num)
{
    if (num < 0)
    {
        return -num;
    }
    return num;
}
