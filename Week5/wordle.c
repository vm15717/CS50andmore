#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

const int char_size = 20;
const int word_size = 5;
void get_word(char*, char*);
int file_length(char*);
void word_correction(char*);
void play_game(char*, int);
int check_word(char*, char*, char*);
void print_hy(int);
bool isvalid(char*);

int main(void)
{
    char *filename = "text.txt";
    char *word = malloc(sizeof(char) * char_size);
    srand(time(NULL));
    get_word(filename, word);
    word_correction(word);
    int ng;
    do
    {
        printf("Please enter the number of guesses you would like to have (between 1 and 10 inclusive): ");
        scanf("%i", &ng);
    }
    while (ng < 1 || ng > 10);
    play_game(word, ng);
    free(word);
}

void get_word(char *filename, char* word)
{
    int random_num = rand() % file_length(filename)/2;
    FILE *fptr = fopen(filename, "r");
    char *line = malloc(sizeof(char) * char_size);
    int iter = 0;
    while (fgets(line, sizeof(line), fptr)) 
    {
        if (random_num == iter)
        {
            strcpy(word, line);
        }
        iter++;
    }
    fclose(fptr);
}

int file_length(char *filename)
{
    int iter = 0;
    FILE *fptr = fopen(filename, "r");
    char *line = malloc(sizeof(char) * char_size);
    while (fgets(line, sizeof(line), fptr)) 
    {
        iter++;
    }
    fclose(fptr);
    free(line);
    return iter;
}

void word_correction(char *word)
{
    int count = 0;
    while (*(count + word) != '\0')
    {
        if (*(word + count) == '\n')
        {
            *(word + count) = '\n';
        }
        else
        {
            *(word + count) = toupper(*(word + count));
        }
        count++;
    }
}

void play_game(char *word, int tries)
{
    printf("Wordle!\n");
    printf("You have got %i tries to guess the %i letter word.\n", tries, word_size);
    char *guess = malloc(sizeof(char) * char_size);
    char *guesssofar = malloc(sizeof(char) * char_size);
    for (int i = 0; i < tries; i++)
    {
        do
        {
            printf("Enter your %i guess: ", i + 1);
            scanf("%s", guess);
            word_correction(guess);
        }
        while (strlen(guess) != word_size && isvalid(guess));
        printf("Your guess is: ");
        printf("%s\n", guess);
        int correct = check_word(guess, word, guesssofar);
        if (correct == word_size)
        {
            printf("That is correct!\n");
            return;
        }
        printf("%i of the letters are correct\n", correct);
        printf("%s\n", guesssofar);
        print_hy(word_size);
    }
    printf("The correct word is: ");
    printf("%s", word);
    free(guess);
    free(guesssofar);
}

void print_hy(int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("_");
    }
    printf("\n");
}

int check_word(char *guess, char *word, char *guesssofar)
{
    int len = word_size;
    int correct = 0;
    for (int i = 0; i < len; i++)
    {
        if (*(guess + i) == *(word + i))
        {
            *(guesssofar + i) = *(guess + i);
            correct++;
        }
        else
        {
            *(guesssofar + i) = ' ';
        }
    }
    return correct;
}

bool isvalid(char *word)
{
    int i = 0;
    while (*(word + i) != '\0')
    {
        if (!(*(word + i) <=90 && *(word + i) >=65) || ((*(word + i) <=122 && *(word + i) >=97)))
        {
            printf("false");
            return false;
        }
        i++;
    }
    return true;
}