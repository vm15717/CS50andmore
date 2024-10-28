#include <stdio.h>
#include <math.h>

int armstrong(int number);

int main(void)
{
    int number;
    int answer;
    printf("Enter the number: ");
    scanf("%d", &number);
    answer = armstrong(number);
    if (answer == number)
    {
        printf("%d is an armstrong number.\n", number);
    }
    else
    {
        printf("%d is not an armstrong number.\n", number);
    }
}

int armstrong(int number)
{
    int count = log10(number) + 1;
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += pow(number % 10, count);
        number = number / 10;
    }
    return sum;
}