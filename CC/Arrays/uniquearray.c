#include<stdio.h>
int N;
void unique_array(int *A)
{
    int i=0,j=1,k,temp;
    for(k=1;k<14;k++)
        {
            temp = A[i];
            j++;
            if(A[i]!=A[j])
                A[++i]=A[j];
        }
    N=i;
}

int main()
{
    int A[14]={1,2,2,2,3,3,4,5,6,6,7,8,8,9},i;
    N=14;
    unique_array(A);
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
}