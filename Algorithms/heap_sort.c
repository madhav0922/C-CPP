#include <stdio.h>

int M, N;

void print(int *A)
{
    //Display heap
    int i;
    for (i = 1; i <= M; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x; //not *temp = *x;
    *x = *y;
    *y = temp;
}

void min_heapify(int *A, int i)
{
    int left = 2 * i, right = (2 * i) + 1, smallest = i;
    if (left <= N && A[left] < A[i])
        smallest = left;
    else
        smallest = i;
    if (right <= N && A[right] < A[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(&A[i], &A[smallest]);
        min_heapify(A, smallest);
    }
}

void max_heapify(int *A, int i)
{
    int left = 2 * i, right = (2 * i) + 1, largest = i;
    if (left <= N && A[left] > A[i])
        largest = left;
    else
        largest = i;
    if (right <= N && A[right] > A[largest])
        largest = right;
    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        max_heapify(A, largest);
    }
}

void heap_sort_max(int *A)
{
    int i;
    for (i = N; i >= 2; i--)
    {
        swap(&A[1], &A[N]); //move root to end
        N--;
        max_heapify(A, 1); // 1 here is for i and not N
    }
}

void heap_sort_min(int *A)
{
    int i;
    for (i = N; i >= 2; i--)
    {
        swap(&A[1], &A[N]); //move root to end
        N--;
        min_heapify(A, 1);
    }
}

void build_heap(int *A)
{
    int i, ch;
    printf("\nPress:\n1.Build Max Heap\n2.Build Min Heap\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        for (i = N / 2; i > 0; i--)
            max_heapify(A, i);
        printf("\nMax heap:\n");
        print(A);
        heap_sort_max(A);
        break;
    case 2:
        for (i = N / 2; i > 0; i--)
            min_heapify(A, i);
        printf("\nMin heap:\n");
        print(A);
        heap_sort_min(A);
        break;
    }
}

int main()
{
    int i, x, a[10], ch;
    printf("Enter size of heap\n");
    scanf("%d", &N);
    M = N;
    printf("%d", N);
    printf("Enter elements in heap\n");
    for (i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    build_heap(a);
    printf("\nSorted Heap\n");
    print(a); //prints sorted heap
    //Heap Sort
    // label:
    //     printf("\nHeap Sort?\nPress\nY for Yes\nN for No\n");
    //     scanf("%c", &ch);
    //     if (ch == 'y' || ch == 'Y')
    //         heap_sort(a);
    //     else if (ch == 'n' || ch == 'N')
    //         exit(0);
    //     else
    //         goto label;
}
