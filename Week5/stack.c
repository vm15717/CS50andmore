#include <stdio.h>
#include <stdlib.h>

const int CAPACITY = 50;
typdef struct
{
    char *name = malloc(sizeof(char) * 30);
    char *number = malloc(sizeof(char) * 10);
} person;

typdef struct
{
    person people[CAPACITY];
    int size;
}
stack;
