#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(sizeof(int) * 3);
    if (list == NULL) //malloc can return NULL if computer has no memory.
    {
        return 1;
    }
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;
    int *tmp = malloc(list, 4 * sizeof(int)); // reallocate memory for you.
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    tmp[3] = 4;
    free(list); // freeing original address of list.
    list = tmp;
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
    free(list); // freeing the new chunk of 4.
    return 0;
}