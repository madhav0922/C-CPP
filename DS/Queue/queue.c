#include <stdio.h>
#include <stdlib.h>
static int Front = -1;
static int Rear = -1;
void enqueue(int *Q, int N, int x)
{
    if (Rear == (N - 1))
        printf("\nQueue is full!!!\n");
    if (Rear < N - 1)
        Q[++Rear] = x;
    if (Front == -1)
        Front++;
}

void dequeue(int *Q, int N)
{
    printf("%d dequeued from queue\n", Q[Front]);
    if (Front == Rear)
        Front = Rear = -1;

    if (Front == -1)
    {
        printf("Queue is empty!!!\n");
        exit(0);
    }
    else
        Front++;
}

int main()
{
    int N, Q[10], ch, x, i, k;
    printf("\nEnter size of queue ");
    scanf("%d", &N);
l1:
    printf("\n\nSELECT\n1.Enqueue\n2.Dequeue\n3.Exit\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\nEnter element to enqueue in queue ");
        scanf("%d", &x);
        enqueue(Q, N, x);
        break;
    case 2:
        dequeue(Q, N);
        break;
    case 3:
        printf("Terminated\n");
        exit(0);
    }

    printf("\nElements in Queue: ");
    for (k = Front; k <= Rear; k++)
        printf("%d ", Q[k]);
    goto l1;
}
