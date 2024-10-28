#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n = 10;
    int val = 524;
    int arr[10] = {87, 54, 231, 23, 65, 72, 80, 99, 1, 10};
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            printf("found.\n");
            return 0;
        }
    }
    printf("not found.\n");
    return -1;
}