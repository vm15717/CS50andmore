#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *word = malloc(sizeof(char) * 20); 
    //malloc memory allocation. ask for memory in advance. return the address of the first byte that is free. It is not null terminated like for strings.
    //free up the memory after calculation.
    //if you dont free memory computer freezes. Always free up the memory after you are done with it.
    printf("s: ");
    fgets(word, sizeof(word), stdin);
    char *word2 = word;
    if (strlen(word2) > 0) // to avoid segmentation fault
    {
        word2[0] = toupper(word2[0]); 
    }
    printf("The word is %s\n", word);
    printf("The word is %s\n", word2);
    free(word);
}