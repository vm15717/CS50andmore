#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void allocate_random_values(int**, int, int);
void print_arr(int**, int, int);
void matrix_multiply(int**, int**, int**, int, int, int);
void dynamic_allocate(int**, int, int);

int main(void)
{
    srand(time(NULL));   // Initialization, should only be called once.
    //int r = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
    int nrows1 =  1 + rand() % 10;
    int ncols1 =  1 + rand() % 10;
    int ncols2 =  1 + rand() % 10;
    //int **A = NULL;
    //dynamic_allocate(A, nrows1, ncols1);
    int **A = malloc(sizeof(int*) * nrows1);
    int **B = malloc(sizeof(int*) * ncols1);
    int **C = malloc(sizeof(int*) * nrows1);
    for (int i = 0; i < nrows1; i++)
    {
        A[i] = malloc(sizeof(int) * ncols1);
    }
    for (int i = 0; i < ncols1; i++)
    {
        B[i] = malloc(sizeof(int) * ncols2); 
    }
    for (int i = 0; i < nrows1; i++)
    {
        C[i] = malloc(sizeof(int) * ncols2); 
    }
    allocate_random_values(A, nrows1, ncols1);
    allocate_random_values(B, ncols1, ncols2);
    printf("A: ");
    printf("\n");
    print_arr(A, nrows1, ncols1);
    printf("B: ");
    printf("\n");
    print_arr(B, ncols1, ncols2);
    matrix_multiply(A, B, C, nrows1, ncols1, ncols2);
    printf("C: ");
    printf("\n");
    print_arr(C, nrows1, ncols2);
    free(A);
    free(B);
    free(C);
}

void allocate_random_values(int **A, int nrows, int ncols)
{
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            A[i][j] = rand() % 10;
        }
    }   
}

void print_arr(int **A, int nrows, int ncols)
{
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            printf("%i\t", A[i][j]);
        }
        printf("\n");
    }   
}

void matrix_multiply(int **A, int **B, int **C, int nrows1, int ncols1, int ncols2)
{
    for (int i = 0; i < nrows1; i++)
    {
        for (int j = 0; j < ncols2; j++)
        {
            for (int k = 0; k < ncols1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }   
}

void dynamic_allocate(int **A, int nrows, int ncols)
{
    *A = malloc(sizeof(int*) * nrows);
    for (int i = 0; i < nrows; i++)
    {
        A[i] = malloc(sizeof(int) * ncols);
    }
}