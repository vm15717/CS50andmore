#include <stdio.h>

void merge(int*, int, int, int, int, int);
void print_arr(int*, int);
void sort(int*, int, int);

int main(void)
{
    int arr[] = {7, 2, 5, 0, 1, 6, 4, 3};
    printf("The unsorted array is: ");
    print_arr(arr, 8);
    sort(arr, 0 , 8);
    printf("The sorted array is: ");
    print_arr(arr, 8);
}

void sort(int arr[], int start, int end)
{
    if (end - start == 1)
    {
        return;
    }
    else
    {
        int start1 = start;
        int end1 = (end + start)/2;
        int start2 = end1;
        int end2 = end;
        sort(arr, start1, end1);
        sort(arr, start2, end2);
        return merge(arr, start1, end1, start2, end2, end2 - start1);
    }
}

void merge(int arr1[], int start1, int end1, int start2, int end2, int len)
{
    int left[end1-start1];
    int right[end2-start2];
    for (int i = 0; i < end1 - start1; i++)
    {
        left[i] = arr1[i + start1];
    }
    for (int j = 0; j < end2 - start2; j++)
    {
        right[j] = arr1[j + start2];
    }
    int i = 0;
    int j = 0;
    int count = start1;
    while (i < (end1-start1) && j < (end2-start2))
    {
        if (left[i] < right[j])
        {
            arr1[count] = left[i];
            i++;
            count++;
        }
        else if (left[i] >= right[j])
        {
            arr1[count] = right[j];
            j++;
            count++;
        }
    }
    while (i < (end1 - start1))
    {
        arr1[count] = left[i];
        i++;
        count++;
    }
    while (j < (end2 - start2))
    {
        arr1[count] = right[j];
        j++;
        count++;
    }
}


void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%i\t", arr[i]);
    }
    printf("\n");
}