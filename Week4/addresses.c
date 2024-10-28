#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n; //pointer. *p is definition. &n is the address of n. pointers take 8 bytes whereas integers take 4 bytes.
    printf("%i\n", n);
    printf("The address of %p is %p.\n", p, &p); // address of a pointer.
}