#include <stdio.h>
#include <string.h>

int main(void)
{
    char* names[] = {"Carter", "David"};
    char* numbers[] = {"123456", "678901"};
    char name[5];
    printf("Please enter a name: ");
    fgets(name, sizeof(name), stdin);
    for (int i = 0; i < 2; i++)
    {
        printf("%i.\n", strcmp(names[i], name));
        if (strcmp(names[i], name) == 0)
        {
            printf("found the number %s.\n", numbers[i]);
            return 0;
        }
    }
    printf("not found.\n");
    return -1;
}