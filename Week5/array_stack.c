#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int size;
    int *array;
    int top;
}
stack;

stack *create_stack(int);
int isFull(stack);
int isEmpty(stack);
void push(stack *, int);
void print_stack(stack *);
int pop(stack *);
void peek(stack *);

int main(void)
{
    int size;
    printf("What would you want the size of the stack to be?: ");
    scanf("%i", &size);
    stack *st1 = create_stack(size);
    push(st1, 10);
    push(st1, 20);
    push(st1, 30);
    pop(st1);
    print_stack(st1);
    free(st1->array);
    free(st1);
    return 0;
}

stack *create_stack(int size)
{
    stack *arr_stack = malloc(sizeof(stack));
    arr_stack->size = size;
    arr_stack->top = -1;
    arr_stack->array = malloc(sizeof(int) * size);
    return arr_stack;
}

int isFull(stack arr_stack)
{
    if (arr_stack.top == arr_stack.size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int isEmpty(stack arr_stack)
{
    if (arr_stack.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(stack *arr_stack, int val)
{
    if (isFull(*arr_stack))
    {
        printf("The stack is full!!\n");
        return;
    }
    else
    {
        arr_stack->array[++arr_stack->top] = val;
    }
}

void print_stack(stack *arr_stack)
{
    for (int i = arr_stack->top; i > -1; i--)
    {
        printf("%i\n", arr_stack->array[i]);
    }
}

int pop(stack *arr_stack)
{
    if (isEmpty(*arr_stack))
    {
        printf("The stack is empty!!!\n");
        return -1;
    }
    else
    {
        return arr_stack->array[arr_stack->top--];
    }
}

void peek(stack *arr_stack)
{
    if (isEmpty(*arr_stack))
    {
        printf("The stack is empty!!!\n");
        return;
    }
    else
    {
        printf("%i\n", arr_stack->array[arr_stack->top]);
        return;
    } 
}