#include<iostream>
using namespace std;

void insertion_sort(int *A, int n)  
{
    int i,j,key;
    for(j=1;j<n;j++)
       {
           key=A[j];
           i = j-1;
            while(i>(-1) && A[i]>key)
                {
                    A[i+1] = A[i];
                    i--;
                }
            A[i+1] = key;
       } 
}
int main()
    {
        int n,arr[100];
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        insertion_sort(arr,n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }