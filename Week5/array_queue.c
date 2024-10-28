#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *array;
    int size;
    int front;
    int num;
}
queue;

queue *create_queue(int);
void enqueue(queue*, int);
int dequeue(queue*);
void print_queue(queue*);
int isFull(queue);
int isEmpty(queue);

int main(void)
{
    int size;
    printf("Please enter the size of the queue: ");
    scanf("%i", &size);
    queue* queue1 = create_queue(size);
    enqueue(queue1, 10);
    enqueue(queue1, 20);
    int w = dequeue(queue1);
    //printf("%i\n", queue1->front);
    //printf("%i\n", queue1->num);
    print_queue(queue1);
    free(queue1->array);
    free(queue1);
    return 0;
}

queue *create_queue(int size)
{
    queue *arr_queue = malloc(sizeof(queue));
    arr_queue->front = 0;
    arr_queue->size = size;
    arr_queue->array = malloc(sizeof(int) * size);
    arr_queue->num = -1;
    return arr_queue;
}

void enqueue(queue *queue, int val)
{
    if (isFull(*queue))
    {
        printf("The queue is full!\n");
        return;
    }
    else
    {
        queue->array[++queue->num + queue->front] = val;
    }
}

int dequeue(queue *queue)
{
    if (isEmpty(*queue))
    {
        printf("The queue is empty\n");
        return -1;
    }
    else
    {
        queue->num--;
        return queue->array[queue->front++];
    }
}

int isFull(queue queue1)
{
    if (queue1.front + queue1.num + 1 == queue1.size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int isEmpty(queue queue1)
{
    if (queue1.front - queue1.num - 1 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print_queue(queue *queue1)
{
    for (int i = queue1->front; i < queue1->front + queue1->num + 1; i++)
    {
        printf("%i\n", queue1->array[i]);
    }
}