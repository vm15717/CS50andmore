#include <stdio.h>

int binary_search(int*, int, int, int);

int main(void)
{
    int n = 10;
    int arr[] = {1, 35, 54, 61, 129, 246, 411, 589, 999, 1004};
    int val = 10;
    int found = binary_search(arr, 0, n - 1, val);
    if (found == 1)
    {
        printf("found.\n");
    }
    else
    {
        printf("not found.\n");
    }
}

int binary_search(int arr[], int start, int end, int val)
{
    if (start == end)
    {
        if (arr[start] == val)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else 
    {
        int middle = (start + end) / 2;
        if (arr[middle] == val)
        {
            return 1;
        }
        else if (arr[middle] > val)
        {
            return binary_search(arr, start, middle - 1, val);
        }
        else if (arr[middle] < val)
        {
            return binary_search(arr, middle + 1, end, val);
        }
    }
}

