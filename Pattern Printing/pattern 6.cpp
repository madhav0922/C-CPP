/*
i/p: 3
o/p:
333
313
323
333  
*/

#include<iostream>
using namespace std;

int main()
    {
        int i,n;
        cout<<"enter the value of n\n";
        cin>>n;
        for(i=0;i<=n;i++)
            {
                cout<<n;
                if(i%n==0)
                    cout<<n;
                else
                    {
                        cout<<i;
                    }
                cout<<n; 
                cout<<endl;
            }
    }