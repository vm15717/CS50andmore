#include <stdio.h>
#include <cs50.h>

int main(void){
    char first[20];
    char last[20];
    printf("Please enter your first name: ");
    scanf("%s", first);
    printf("Please enter your last name: ");
    scanf("%s", last);
    //printf("Your name is : %s\n", str);
    printf("Hello, %s %s!\n", first, last); //% is seen as a special sign.
    printf("I got 100%%\n"); //%% is seen as a single % symbol.
}