#include <stdio.h>
#include <stdlib.h>

void sieve(int*, int);
void allocate(int*, int);
void print_arr(int*, int);
int power(int, int);
int sqroot(int);
int arr_correct(int*, int, int*);
int main(void)
{
    int n;
    printf("Please enter the number until which all the primes are to be found: ");
    scanf("%i", &n);     
    int *arr = malloc(sizeof(int) * n);
    allocate(arr, n);
    print_arr(arr, n);
    sieve(arr, n);
    int *arr2 = malloc(sizeof(int) * n);
    int len2 = arr_correct(arr, n, arr2);
    print_arr(arr2, len2);
    free(arr);
    free(arr2);
}

void allocate(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(arr + i) =  (i + 1);
    }
}

void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %i", *(arr + i));
        if (i != n - 1)
        {
            printf(",");
        }
    }
    printf(".\n");
}

void sieve(int *arr, int n)
{
    int sqr = sqroot(n);
    for (int i = 1; i < sqr; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (*(arr + j) % *(arr + i) == 0)
                {
                    *(arr + j) = 0;
                }
            }
        }
    }
}

int sqroot(int n)
{
    int j = 0;
    while (power(j, 2) < n)
    {
        j++;
    }
    return j + 1;
}

int power(int i, int j)
{
    int prod = 1;
    if (j == 0)
    {
        return prod;
    }
    else
    {
        for (int k = 0; k < j; k++)
        {
            prod *= i;
        }
        return prod;
    }
}

int arr_correct(int *arr, int n, int *out)
{
    //int *out = malloc(sizeof(int) * n);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) != 0)
        {
            *(out + j) = *(arr + i);
            j++;
        }
    }
    return j;
}