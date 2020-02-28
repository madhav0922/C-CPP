#include<iostream>
using namespace std;

/*
1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index 
  stores the sum of previous counts. 
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

The modified count array indicates the position of each object in 
the output sequence.
 
  3) Output each object from the input sequence followed by 
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place 
  next data 1 at an index 1 smaller than this index.

  Output:    1 1 2 2 4 5 7
*/

void counting_sort(int *A, int n)
    {
        int i,output[n],count[10]={0};
        for(i=0;i<n;i++)
            {
                count[A[i]]++;
            }
        for(i=1;i<=n;i++)
            {
                count[i] += count[i-1];
            }
        for(i=0;A[i];i++)
            {
                output[count[A[i]]-1] = A[i];       //fill values in output according to original Array.
                --count[A[i]];
            }
        for(int i=0;i<n;i++)
            A[i] = output[i];
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
        counting_sort(arr,n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }
