/*
i/p:
3 4
o/p:
3
44
555
6666
555
44
3
*/

#include<iostream>
using namespace std;

int main()
    {
        int m,n,i,j;
        cout<<"Enter value of m and n seperated by a space\n";
        cin>>m>>n;
        for(i = 1 ; i <= 4 ; i++)
            {
                for(j = 1 ; j <= i ; j++)
                    {
                        cout<<m;
                    }
                m++;
                cout<<endl;
            }
        m=m-2;
        for(i = 3 ; i >= 1 ; i--)
            {
                for(j = 1 ; j <= i ; j++)
                    {
                        cout<<m;
                    }
                m--;
                cout<<endl;
            }
    }