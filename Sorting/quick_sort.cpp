#include<iostream>
using namespace std;

void swap (int *a , int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

int quick_sort(int *A,int low,int high)
    {
        int i=low-1,j;
        int pivot = A[high];
        for(j=low;j<high;j++)
            {
                if(A[j]<=pivot)
                    {
                        i++;
                        if(i!=j)
                            swap(&A[i],&A[j]);
                    }
            }
        swap(&A[i+1],&A[high]);
        return (i+1);
    }


void quick_sort_partition(int *A,int low,int high)
    {
        if(low<high)
            {
                int pivot = quick_sort(A,low,high);
                quick_sort_partition(A,low,pivot-1);        // pivot - 1 since pivot is at its correct position already and is the lesser half than pivot
                quick_sort_partition(A,pivot+1,high);       // pivot + 1 since it is the greater half
            }
    }

int main()
{
    int i,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    quick_sort_partition(arr,0,n-1);
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}