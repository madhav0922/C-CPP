/*
i/p: 4
o/p:
1   
2*3
4*5*6
7*8*9*10
7*8*9*10
4*5*6
2*3
1
*/

#include<iostream>
using namespace std;

int main()
    {
        int m,i,j,k=1;
        cout<<"enter value of m\n";
        cin>>m;
        for(i=1;i<=m;i++)
            {
                for(j=1;j<=i;j++)
                    {
                        cout<<k;
                        if(j<i)
                            cout<<"*";
                        k++;
                    }
                cout<<endl;
            }
        
        //k=11
        
        for(i=m;i>=1;i--)
            {
                k = k-i;
                for(j=1;j<=i;j++)
                    {
                        cout<<k;
                        if(j<i)
                            cout<<"*";
                        k++;
                    }
                cout<<endl;
                k = k-i;
            }     
    }

