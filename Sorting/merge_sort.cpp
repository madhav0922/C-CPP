#include<iostream>
using namespace std;

void merge(int *A, int low, int mid, int high)
    {
        int p = mid-low+1;
        int q = high - mid;
        int L[p+1],R[q+1],i,j,k;
        for(i=1;i<=p;i++)
            L[i] = A[low+i-1];
        for(j=1;j<=q;j++)
            R[j] = A[mid+j];
        i = j = 1;
        //L[p+1] = INT8_MAX;
        //R[q+1] = INT8_MAX;
        for(k=low;k<high;k++)
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
            }
    }

int merge_sort(int *A,int low, int high)
    {
        int mid;
        if(low == high)
        {
            return A[low];
        }
        else
        {
            mid = low + (high-low)/2;
            merge_sort(A,low,mid);
            merge_sort(A,mid+1,high);
            merge(A,low,mid,high);
        }
        return -1;
    }

int main()
    {
        int n,arr[100];
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        merge_sort(arr,1,n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }