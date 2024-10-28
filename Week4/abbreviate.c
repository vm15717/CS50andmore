#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{
    char *word = malloc(sizeof(char) * 100);
    printf("Please enter the word: ");
    scanf("%[^\n]", word);
    char *abbr = malloc(sizeof(char) * 10);
    int count = 0;
    int abbcount = 0;
    if (word != NULL)
    {
        while (*(word + count) != '\0')
        {
            if (*(word + count) == ' ' || *(word + count) == '-')
            {
                *(abbr + abbcount) = toupper(*(word + count + 1));
                abbcount++;
            }
            else if (count == 0)
            {
               *(abbr + abbcount) = toupper(*(word + count));
               abbcount++; 
            }
            count++;
        }
        printf("The abbreviation of the word %s is %s.\n", word, abbr);
        return 0;
    }
    else
    {
        return -1;
    }
    free(word);
    free(abbr);
}

