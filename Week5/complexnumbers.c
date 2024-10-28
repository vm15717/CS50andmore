#include <stdio.h>

typedef struct
{
    double real; //.* can be written as ->
    double imag;
}
comp_num;

double power(int, int);
double absolute(comp_num);
comp_num inverse(comp_num);
comp_num conjugate(comp_num);
comp_num add(comp_num, comp_num);
comp_num multiply(comp_num, comp_num);
comp_num negative(comp_num);
void print_comp(comp_num);

int main(void)
{
    comp_num com1;
    comp_num com2;
    com1.real = 1;
    com1.imag = 2;
    com2.real = 4;
    com2.imag = 1;
    comp_num com3;
    com3 = multiply(com1, com2);
    com3 = conjugate(com3);
    print_comp(com3);
}


double absolute(comp_num com1)
{
    return power(com1.real, 2) + power(com1.imag, 2);
}


double power(int num, int exp)
{
    double prod = 1;
    for (int i = 0; i < exp; i++)
    {
        prod *= num;
    }
    return prod;
}

comp_num inverse(comp_num com1)
{
    comp_num com2;
    double abscom1 = absolute(com1); 
    com2.real = com1.real/abscom1;
    com2.imag = com1.imag/abscom1;
    return com2;
}

comp_num conjugate(comp_num com1)
{
    comp_num com2;
    com2.real = com1.real;
    com2.imag = -com2.imag;
    return com2;
}

comp_num add(comp_num com1, comp_num com2)
{
    comp_num com3;
    com3.real = com1.real + com2.real;
    com3.imag = com1.imag + com2.imag;
    return com3;
}

comp_num subtract(comp_num com1, comp_num com2)
{
    return add(com1, negative(com2));
}

comp_num multiply(comp_num com1, comp_num com2)
{
    comp_num com3;
    com3.real = com1.real * com2.real - com1.imag * com2.imag;
    com3.imag = com1.imag * com2.real + com2.imag * com1.real;
    return com3;
}

comp_num divide(comp_num com1, comp_num com2)
{
    return multiply(com1,inverse(com2));
}
void print_comp(comp_num com)
{
    if (com.imag < 0)
    {
        printf("%lf - %lfi \n", com.real, -com.imag);
    }
    else
    {
        printf("%lf + %lfi \n", com.real, com.imag);
    }
}

comp_num negative(comp_num com1)
{
    comp_num com2;
    com2.real = -com1.real;
    com2.imag = -com1.imag;
    return com2;
}
