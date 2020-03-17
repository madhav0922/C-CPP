#include<iostream>
using namespace std;
int main()
    {
        int i,j,key=2,n=5,sum=0,index;
        //cin>>n>>key;
        int a[5] = {1,-2,3,4,5},b[5];
        //int a[n];
        //for(i=0;i<n;i++)
          //  cin>>a[i];

        for(i=0;i<n;i++)    
        {
            sum=0;
            if(a[i]>0)
                {
                    for(j=i+1;j<=(key+i);j++)
                        {   
                            //cout<<j;
                            if(j==n||j>n)
                                {
                                    //index = j-n;
                                    sum += a[j-n];
                                }
                            else
                                sum += a[j];
                        }
                }
            else
                {
                    for(j=i-1;j>=i-key;j--)
                        {
                            if(j<0)
                                sum += a[n+j];
                            else
                            {
                                sum += a[j];
                            }
                            
                        }
                }
            
            b[i] = sum;
        }
        
        for(i=0;i<n;i++)
            cout<<b[i]<<" ";
        cout<<endl;
    }