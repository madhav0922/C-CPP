/*
i/p: 3              4
o/p:
1               1            
2*2             2*2
3*3*3           3*3*3
3*3*3           4*4*4*4
2*2             4*4*4*4
1               3*3*3
                2*2
                1
*/

#include<iostream>
using namespace std;

int main()
    {
        int m,i,j;
        cout<<"enter value of m\n";
        cin>>m;
        for(i=1;i<=m;i++) 
            {
                for(j=1;j<=i;j++)
                    {
                        cout<<i;
                        if(j<i)
                            {
                                cout<<"*";
                            }
                    }
                cout<<endl;
            }
        for(i=m;i>=1;i--)
            {
                for(j=i;j>=1;j--)
                    {
                        if(j<i)
                            cout<<"*";
                        cout<<i;
                    }
                cout<<endl;
            }
    }