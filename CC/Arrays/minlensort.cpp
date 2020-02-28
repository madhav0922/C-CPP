#include<iostream>
using namespace std;

int main()
{
    int a[11]= {11,13,21,31,26,41,33,32,36,52,62};
        int i,j,k,l,low,high,min,max,N=11,low_2,high_2;
        min=a[0];
        max=a[0];
        for(i=0;i<N;i++)
            {
                if(a[i+1]<a[i])
                    {   
                        low=i;
                        break;
                    }   
            }
            cout<<low;
        for(i=N-1;i>=0;i--)
            {
                if(a[i-1]>a[i])
                    {
                        high = i;
                        break;
                    }
            }
        
        for(i=low;i<=high;i++)
            {
                if(a[i]<min)
                    min = a[i];   
            }
        
        for(i=low;i<=high;i++)
            {
                if(a[i]>max)
                    max = a[i];   
            }

        for(i=0;i<=low;i++)
            {
                if(a[i]>min)
                    {
                        low_2=i;
                        break;
                    }
            }
        for(i=N-1;i>=high;i--)
            {
                if(a[i]<max)
                    {
                        high_2=i-1;
                        break;
                    }
            }
        cout<<low_2<<" "<<high_2;


}