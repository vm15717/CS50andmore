#include <stdio.h>

void swap(int*, int*);
void print_arr(int*);

int main(void)
{
    int arr[] = {7, 0, 2, 6, 4, 1, 3, 5};
    printf("The unsorted list is: ");
    print_arr(arr);
    for (int i = 0; i < 8; i++)
    {
        int min_idx = i;
        for (int j = i+1; j < 8; j++)
        {
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
    printf("The sorted list is: ");
    print_arr(arr);
}


void swap(int* a1, int* a2)
{
    int dummy;
    dummy = *a1;
    *a1 = *a2;
    *a2 = dummy;
}

void print_arr(int arr[])
{
    for (int i = 0; i < 8; i++)
    {
        printf("%i\t", arr[i]);
    }
    printf("\n");
}