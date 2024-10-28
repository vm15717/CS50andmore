#include <stdio.h>
#include <string.h>

typedef struct 
{
   char name[7];
   char number[20];
}
person;

int main(void)
{
    person people[2];
    strcpy(people[0].name, "David");
    strcpy(people[1].name, "Carter");
    strcpy(people[0].number, "123344");
    strcpy(people[1].number, "313213");
    char name[7];
    printf("Please enter a name: ");
    fgets(name, sizeof(name), stdin);
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found and the number is %s.\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}