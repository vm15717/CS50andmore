#include <stdio.h>

void swap(int*, int*);
void print_arr(int*);

int main(void)
{
    int arr[] = {7, 0, 2, 6, 4, 1, 3, 5};  
    printf("The unsorted array is: ");
    print_arr(arr);
    for (int i = 0; i < 8; i++)
    {
        int swapnum = 0;
        for (int j = 0; j < 7; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);  
                swapnum++; 
            }
        }
        if (swapnum == 0)
        {
            break;
        }
    }
    printf("The sorted array is: ");
    print_arr(arr);
}

void swap(int* a1, int* a2)
{
    int dummy;
    dummy = *a1;
    *a1 = *a2;
    *a2 = dummy;
}

void print_arr(int* arr)
{
    for (int i = 0; i < 8; i++)
    {
        printf("%i\t", arr[i]);
 
    }
    printf("\n");
}