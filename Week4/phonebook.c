#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a"); // C thing
    char *name = malloc(sizeof(char) * 20);
    char *number = malloc(sizeof(char) * 20);
    printf("Please enter a name: ");
    scanf("%s", name);
    printf("Please enter a number: ");
    scanf("%s", number);
    fprintf(file, "%s,%s\n", name, number);
    fclose(file);
    free(name);
    free(number);
}