#include <stdio.h>

void draw(int);

int main(void)
{
    draw(10);
}

void draw(int len)
{
    if (len <= 0)
    {
        return;
    }
    else
    {
        draw(len - 1);
        for (int i = 0; i < len; i++)
        {
            printf("#\t");
        }
        printf("\n");
    }
}