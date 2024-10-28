#include <stdio.h>

int validate(char*, char*);
int stringlen(char*);
int hamming(char*, char*);
int char_check(char*);

int main(int argc, char** argv)
{
    if (argc != 3)
    {  
        printf("Please enter two DNA sequences.\n");
        return 1;
    }
    int check = validate(argv[1], argv[2]);
    if (check == 0)
    {
        printf("The sequences are not of equal length.\n");
        return 1;
    }
    else if (check == 1)
    {
        printf("The sequence needs to be a combination of the characters A,T,C,G and nothing else. They are case sensitive.\n");
        return 1;
    }
    else if (check == 2)
    {
        int hamming_distance = hamming(argv[1], argv[2]);
        printf("The Hamming distance between %s and %s is %i\n", argv[1], argv[2], hamming_distance);
        return 0;
    }
}

int validate(char word1[], char word2[])
{
    int len1 = stringlen(word1);
    int len2 = stringlen(word2);
    if (len1 != len2)
    {
        return 0;
    }
    else
    {
        int cc1 = char_check(word1);
        int cc2 = char_check(word2);
        if (cc1 && cc2)
        {
            return 2;
        }
        else 
        {
            return 1;
        }
    }
}

int char_check(char word[])
{
    int count = 0;
    while (word[count] != '\0')
    {
        char w = word[count];
        if (w != 'A' && w != 'G' && w != 'T' && w != 'C')
        {
            return 0;
        }
        count++;
    }
    return 1;
}

int stringlen(char word[])
{
    int count = 0;
    while (word[count] != '\0')
    {
        count++;
    }
    return count;
}

int hamming(char word1[], char word2[])
{
    int count = 0;
    int dist = 0;
    while (word1[count] != '\0')
    {
        if (word1[count] != word2[count])
        {
            dist++;
        }
        count++;
    }
    return dist;
}