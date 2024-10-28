#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numer;
    int denom;
}
rat_num;

void print_num(rat_num);
rat_num add_rat_num(rat_num, rat_num);
rat_num multiply_rat_num(rat_num, rat_num);
void gcd_check(rat_num *);
rat_num negative_rat(rat_num *);
rat_num invert_rat(rat_num *);
int gcd(int, int);
int check_valid(char *);
rat_num stringtoratnum(char *);
int strtoint(char *);
int slen(char *);
void string_correct(char *);
int power(int, int);
void remove_spaces(char *);

int main(void)
{
    char *frac = malloc(sizeof(char) * 20);
    rat_num rnum;
    printf("Enter a rational number: \n");
    scanf("%[^\n]", frac);
    rnum = stringtoratnum(frac);
    free(frac);
    //rnum.numer = 6;
    //rnum.denom = 2;
    //rat_num rnum1;s
    //rnum1.numer = 5;
    //rnum1.denom = 4;
    //rat_num rnum2 = add_rat_num(rnum, negative_rat(&rnum1));
    print_num(rnum);
}


void print_num(rat_num rnum)
{
    printf("(%i, %i)\n",rnum.numer, rnum.denom);
}

rat_num add_rat_num(rat_num rat1, rat_num rat2)
{
    rat_num rat3;
    rat3.numer = (rat1.numer * rat2.denom + rat1.denom * rat2.numer);
    rat3.denom = (rat1.denom * rat2.denom);
    gcd_check(&rat3);
    return rat3;
}


rat_num multiply_rat_num(rat_num rat1, rat_num rat2)
{
    rat_num rat3;
    rat3.numer = (rat1.numer * rat2.numer);
    rat3.denom = (rat1.denom * rat2.denom); 
    gcd_check(&rat3);
    return rat3;
}
void gcd_check(rat_num *rat)
{
    int num = rat->numer;
    int den = rat->denom;
    int gcd_nd = 1;
    if (num > den)
    {
        gcd_nd = gcd(num, den);
    }
    else
    {
        gcd_nd = gcd(den, num);
    }
    rat->numer = num/gcd_nd;
    rat->denom = den/gcd_nd;   
}

int gcd(int num, int den)
{
    if (den == 0)
    {
        return num;
    }
    else
    {
        return gcd(den, num % den);
    }
}

rat_num negative_rat(rat_num *rat)
{
    rat->numer = -rat->numer;
    return *rat;
}

rat_num invert_rat(rat_num *rat)
{
    int temp;
    temp = rat->denom;
    rat->denom = rat->numer;
    rat->numer = temp; 
    return *rat;
}

rat_num stringtoratnum(char *string)
{
    int count = 0;
    string_correct(string);
    int len = slen(string);
    char *num = malloc(sizeof(char) * len);
    char *den = malloc(sizeof(char) * len);
    int comma = 0;
    int numd = 0;
    int numi = 0;
    while (*(string + count) != '\0')
    {
        if (*(string + count) == ',')
        {
            comma = 1;
        }
        if (comma == 0)
        {
            *(num + numi) = *(string + count);
            numi++;
        }
        else
        {
            *(den + numd) = *(string + count + 1);
            numd++;
        }
        count++;
    }
    rat_num rat;
    rat.numer = strtoint(num);
    rat.denom = strtoint(den);
    free(num);
    free(den);
    return rat;
}

int check_valid(char *string)
{
    int count = 0;
    int space = 0;
    int comma = 0;
    int brackets = 0;
    int nums = 0;
    while (*(string + count) != '\0')
    {
        //printf("%c\n", *(string + count));
        if (*(string + count) == ' ')
        {
            space++;   
        }
        else if (*(string + count) == ',')
        {
            space = 0;
            nums = 0;
            comma++;
        }
        else if (*(string + count) == '(')
        {
            brackets++;
        }
        else if (*(string + count) == ')')
        {
            brackets--;
        }
        else if ((*(string) + count) <= 57 && *(string + count) >= 48)
        {
            nums++;
        }
        if (!(((*(string + count) <= 57 && *(string + count) >= 48) || *(string + count) == ' ' || *(string + count) == ',' || *(string + count) == ')' || *(string + count) =='(')))
        {
            return 1;   
        }
        else
        {
            if ((space > 1 && comma <= 1 && nums > 1) || (comma > 1 ))
            {
                return 1;
            }
        }
        count++;
    }
    if (brackets == 0)
    {
        return 0;   
    }
    else
    {
        return 1;
    }
}

int slen(char *string)
{
    int count = 0;
    while (*(string + count) != '\0')
    {
        count++;
    }
    return count;
}

void string_correct(char *string)
{
    int count = 0;
    while (*(string + count) != '\0')
    {
        if (*(string + count) == '(')
        {
            *(string + count) = ' ';
            count = 0;
        }
        else if (*(string + count) ==')')
        {
            *(string + count) ='\0';
        }
        count++;
    }
    remove_spaces(string);
}

int strtoint(char *string)
{
    int num = 0;
    int len = slen(string);
    //printf("%i\n", len);
    int count = 0;
    while (*(string + count) != '\0')
    {
        num += power(10, len - count - 1) * (*(string + count) - 48);
        count++;
    }
    return num;
}

int power(int num, int exp)
{
    int prod = 1;
    for (int i = 0; i < exp; i++)
    {
        prod *= num;
    }
    return prod;
}

void remove_spaces(char* s) 
{
    char* d = s;
    do {
        while (*d == ' ') 
        {
            ++d;
        }
    } while (*s++ = *d++);
}