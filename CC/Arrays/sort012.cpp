#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int main()
    {
        int v[14]= {0,1,0,1,2,0,1,2,0,0,1,1,2,2};
        int low=0,mid=0,high=13;
        for(int i=0;i<14;i++)
            {
                if(low<high)
                {
                    if(v[mid]==0)
                        {
                            swap(&v[low],&v[mid]);
                            low++;
                            mid++;
                        }
                    else if(v[mid]==1)
                        mid++;
                    else if(v[mid]==2)
                        {
                            swap(&v[mid],&v[high]);
                            high--;
                        }
                }
            }
        for(int i=0;i<14;i++)
            cout<<v[i]<<" ";
        return 0;
    }