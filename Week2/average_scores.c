#include <stdio.h>

float average(int arr[], int arr_len);

int main(void)
{
    int len = 0;
    printf("Number of test scores to add up?: ");
    scanf("%i", &len);
    int scores[len];
    for (int i = 0; i < len; i++)
    {
        printf("What's the score of exam %i: ", i);
        scanf("%i", &scores[i]);
    }
    printf("The average of the scores is %f\n", average(scores, len));
}

float average(int scores[], int arr_len)
{
    int sum = 0;
    for (int i = 0; i < arr_len; i++)
    {
        sum += scores[i];
    }
    return (float) sum/arr_len;
}