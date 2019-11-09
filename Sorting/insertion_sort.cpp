#include<iostream>
using namespace std;

void insertion_sort(int *A)
    {
        int i,j,key;
        for(j=1;j<5;j++)
            {
                key = A[j];
                i=j-1;
                while(i>(-1) && A[i]>key)
                    {
                        A[i+1]=A[i];        //A[j+1]=A[j] NO, because j is only providing the key.
                        i=i-1;
                    }
                A[i+1]=key;
            }
    }

int main()
    {
        int arr[5];
        for(int i=0;i<5;i++)
            cin>>arr[i];

    insertion_sort(arr);

        for(int i=0;i<5;i++)
            cout<<arr[i]<<" ";
    
    }