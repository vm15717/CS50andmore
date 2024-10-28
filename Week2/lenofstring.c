#include <stdio.h>
#include <string.h>
int len(char* );
int main(void)
{
    char word[20];
    int length = 0;
    printf("Enter the word: ");
    fgets(word, sizeof(word), stdin);
    length = len(word);
    printf("The length of %s is %i\n", word, length);
    printf("The length of %s is %lu\n", word, strlen(word));
}

int len(char word[])
{
    int count = 0;
    while(word[count] != '\0')
    {
        if (word[count] != '\t')
        {
            count++;
        }
    }
    return count;
}