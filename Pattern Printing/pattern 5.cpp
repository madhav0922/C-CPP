/*
i/p: 4
o/p:
1*2*3*4*17*18*19*20
--5*6*7*14*15*16
----8*9*12*13
------10*11
*/

#include<iostream>
using namespace std;

int main()
    {
        int i,j,k,l,m,n;
        cout<<"enter value of n\n";
        cin>>n;
        k=1,m=(n*n)+n+1;
        for(i=n;i>=1;i--)
            {
                for(l=0;l<n-i;l++)
                    cout<<"--";
                m = m - i;
                for(j=1;j<=i;j++)
                    {
                        cout<<k++;
                        cout<<"*";
                    }
                for(j=1;j<=i;j++)
                    {
                        cout<<m++;
                        if(j<i)
                            cout<<"*";
                    }
                m = m - i;
                cout<<endl;
            }
    }