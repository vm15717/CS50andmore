#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int row_size = 6;
const int ops_size = 4;
const int big_size = 4;
void co_array(int *);
int create_num(int *, char *);
void shuffle(int *); //Fisher - Yates Shuffle
int check_arr(int *, int);
void print_arr(int *);

int main(void)
{
    srand(time(NULL));
    char ops[] = {'+', '*', '/', '-'};
    int *arr = malloc(sizeof(int) * row_size);
    co_array(arr);
    print_arr(arr);
    shuffle(arr);
    print_arr(arr);
    int num;
    do
    {
        num = create_num(arr, ops);
    }
    while (num < 0);
    printf("The number is %i\n", num + (rand() % 2));
    free(arr);
}

void co_array(int *arr)
{
    int arr1[] = {100, 25, 50, 75};
    int big_count = 0;
    int big_idx[] = {-1, -1, -1, -1};
    for (int i = 0; i < row_size; i++)
    {
        char *num = malloc(sizeof(char) * 2);
        do
        {
            printf("Big number(b) or small number(s)?:");
            scanf("%s", num);
        } 
        while (num[0] != 's' && (num[0] != 'b' || big_count > (big_size - 1))); 
        if (num[0] == 'b')
        {
            int k = -1;
            do
            {
                k = rand() % ops_size;
            } 
            while (k < 0 || check_arr(big_idx, k));
            *(arr + i) = arr1[k];
            *(big_idx + big_count) = k;
            big_count++;
        }
        else if (num[0] == 's')
        {
            int m;
            do 
            {
                m = rand() % 10 + 1;
            }
            while (check_arr(arr, m));
            *(arr + i) = m;
        }
        printf("%i\n", *(arr + i));
        free(num);
    }
}

int create_num(int *arr, char *ops)
{
    int cnum = 0;
    int i = 0;
    while (i < row_size - 1)
    {
        int j = rand() % ops_size;
        if (*(ops + j) == '+')
        {
            cnum += *(arr + i) + *(arr + i + 1);
            i++;
        }
        else if (*(ops + j) == '-') 
        {
            cnum += *(arr + i) - *(arr + i + 1);  
            i++;
        }
        else if (*(ops + j) == '/')
        {
            if (*(arr + i) % *(arr + i + 1) == 0)
            {
                cnum += *(arr + i) / *(arr + i + 1);
            }
            else if (*(arr + i + 1) % *(arr + i) == 0)
            {
                cnum += *(arr + i + 1) / *(arr + i);    
            }
            else
            {
                cnum += *(arr + i) * *(arr + i + 1);
            }
            i++;
        }
        else if (*(ops + j) == '*')
        {
            cnum += *(arr + i) * *(arr + i + 1);
            i++;
        }
        i++;
    }
    return cnum;
}

void print_arr(int *arr)
{
    for (int i = 0; i < row_size; i++)
    {
        printf("%i\t", *(arr+i));
    }
    printf("\n");
}

int check_arr(int *arr, int w)
{
    int count = 0;
    for (int i = 0; i < big_size; i++)
    {
        if (*(arr + i) == w)
        {
            count += 1;
        }
    }
    return count;
}

void shuffle(int *arr)
{
    for (int i = row_size - 1; i > 0; i--)
    {
        int j = rand() % i;
        int temp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
    }
}