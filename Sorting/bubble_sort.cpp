#include<iostream>
using namespace std;

void bubble_sort(int *A, int n)
    {
        int temp,i,j,min;
        for(i=0;i<n-1;i++)
            {
                for(j=0;j<n-i-1;j++)
                    {
                        if(A[j+1]<A[j])
                            {
                                temp = A[j];
                                A[j] = A[j+1];
                                A[j+1] = temp;
                            }
                    }
            }
    }

int main()
    {
        int n,ch;
        int arr[] = {1,4,1,2,7,5,2};
        n = sizeof(arr)/sizeof(arr[0]);
        // cin>>n;
        // int arr[n];
        // for(int i=0;i<n;i++)
        //     cin>>arr[i];
        bubble_sort(arr,n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }