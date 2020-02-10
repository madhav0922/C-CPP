/*
i/p: 5
o/p:
1
3*2
4*5*6
10*9*8*7
11*12*13*14*15
*/

#include<iostream>
using namespace std;

int main()
    {
        int m,i,j,k=0;
        cout<<"Enter value of m\n";
        cin>>m;

        for(i=1;i<=m;i++)
            {
                if(i%2!=0)
                    {
                        k=k+i;
                        for(j=1;j<=i;j++)
                            {
                                cout<<k;
                                if(j<i)
                                    cout<<"*";
                                k++;
                            }
                        cout<<endl;
                    }
                else
                {
                        k = k+i-1;
                        for(j=1;j<=i;j++)
                            {
                                cout<<k;
                                if(j<i)
                                    cout<<"*";
                                k--;
                            }
                        cout<<endl;
                }
                
            }
    }