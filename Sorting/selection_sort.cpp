#include<iostream>
using namespace std;

void selection_sort(int *a)
    {
        int min,j,temp;
        for(int i=0;i<5;i++)
            {
                min = i;
                for(j=i+1;j<5;j++)
                    {
                        if(a[j]<a[min])
                            min = j;
                    }
                cout<<j;
                cout<<min;
                temp = a[min];
                a[min] = a[i];
                a[i] = temp;
            }
    }

int main()
    {
        int arr[5];
        for(int i=0;i<5;i++)
            cin>>arr[i];

        selection_sort(arr);

        for(int i=0;i<5;i++)
            cout<<arr[i]<<" ";
    
    }

// single source shortest path
// dijksta
// cycle detection (bfs) (disjoint sets)

