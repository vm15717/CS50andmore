#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_isogram(const char*);

int main(void){
    char word[20];
    printf("Please enter the word: ");
    fgets(word, sizeof(word), stdin);
    bool val = is_isogram(word);
    printf("%i\n", val);
}

bool is_isogram(const char word[])
{
    int size = strlen(word) - 1;
    //printf("%d\n", size);
    for (int i = 0;i < size;i++)
    {
        if (isalpha(word[i]))
        {
            for (int j = 0;j < size; j++)
            {
                if ((word[i] == word[j]) && (i != j))
                {
                    return false;
                }
            }
        }
    }
    return true;
}