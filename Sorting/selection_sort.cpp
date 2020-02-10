#include<iostream>
using namespace std;


void swap(int *x, int *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }
void selection_sort(int *A,int n)
    {
        int i,j,min;
        for(i=0;i<n;i++)
            {
                min = i;
                for(j = i+1 ;j<n;j++)
                    {
                        if(A[j]<A[min])
                            {
                                min = j;
                            }
                    }
                swap(&A[i],&A[min]);
            }
    }

int main()
    {
        int n,arr[100];
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        selection_sort(arr,n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }