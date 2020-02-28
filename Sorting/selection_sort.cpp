#include<iostream>
using namespace std;


void swap(int *x, int *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

void selection_sort(int *A, int n)
{
    int i,j,min;
    for(i=0;i<n;i++)
        {
            min = i;
            for(j=i+1;j<n;j++)
                {
                    if(A[j]<=A[min])
                        min = j;
                }
            swap(&A[min],&A[i]);
        }
}

// STABLE SELECTION SORT

void stableSelectionSort(int a[], int n) 
{ 
    // Iterate through array elements 
    for (int i = 0; i < n - 1; i++)  
    { 
  
        // Loop invariant : Elements till a[i - 1] 
        // are already sorted. 
  
        // Find minimum element from  
        // arr[i] to arr[n - 1]. 
        int min = i; 
        for (int j = i + 1; j < n; j++) 
            if (a[min] > a[j]) 
                min = j; 
  
        // Move minimum element at current i. 
        int key = a[min]; 
        while (min > i)  
        { 
            a[min] = a[min - 1]; 
            min--; 
        } 
        a[i] = key; 
    } 
} 

int main()
    {
        int n,ch;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"Enter 1 for unstable 2 for stable\n";
        cin>>ch;
        (ch==1)?selection_sort(arr,n):stableSelectionSort(arr,n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }