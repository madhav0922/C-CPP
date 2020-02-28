#include<iostream>
using namespace std;

void merge(int *A,int low, int mid, int high)
    {
        int n1,n2,i,j,k;
        n1 = mid-low+1;
        n2 = high - mid; 
        int L[n1],R[n2];
        //L[n1+1] = R[n2+1] = INT16_MAX;

            for(i=0;i<n1;i++)
                L[i] = A[low+i];
            for(j=0;j<n2;j++)
                R[j] = A[mid+1+j];
        // for(i=0;i<n1;i++)
        //     cout<<L[i]<<" ";
        // cout<<"\n";
        // for(i=0;i<n2;i++)
        //     cout<<R[i]<<" ";
        // cout<<"\n";
        i=0,j=0,k = low;
        while(i<n1 && j<n2)
            {
                if(L[i]<=R[j])
                    {
                        A[k] = L[i];
                        i++;
                    }
                else
                    {
                        A[k] = R[j];
                        j++;
                    }
                k++;
            }
        // copy remaining elements, if any
        while(i<n1)
            {
                A[k] = L[i];
                k++; i++;
            }
        while(j<n2)
            {
                A[k] = R[j];
                k++; j++;
            }
    }

void merge_sort(int *A,int low,int high)
    {
        if(low<high)
        {
            int mid = low + (high-low)/2;
            merge_sort(A,low,mid);
            merge_sort(A,mid+1,high);
            merge(A,low,mid,high);
        }
    }

int main()
    {
        int n,i;
         cin>>n;
        int arr[n];
         for(i=0;i<n;i++)
            cin>>arr[i];
        merge_sort(arr,0,n-1);
        for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }