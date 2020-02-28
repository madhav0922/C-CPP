#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int* plusOne(int* A, int n1, int *len1) {
    int num=0,digit;
    int i,k,c_zero=0;

    for(i=0;i<n1;i++)
        {
            if(A[i]==0)
                ++c_zero;
            else
                break;
        }
    // if(c_zero == n1)
    //     {
    //         *len1 = 1;
    //         int *B = (int*)malloc((*len1)*sizeof(int));
    //         B[0]=1;
    //         return B;
    //     }
        
        for(i=n1;i>0;i--)
            num += ((A[i])*pow(10,(n1-i)));
        
        printf("%d",num);
        num = num+1;
        
        *len1 = n1-c_zero;
        k = *len1;
        int *C = (int*)malloc((*len1)*sizeof(int));
        while(num>0)
            {
                digit = num%10;
                num /= 10;
                C[k--] = digit;
            }
        return C;
}

int main()
    {
        int A[4] = {1,2,3,4};
        int n1 = 4 ,len1 = 4;
        int *B = plusOne(A, n1, &len1);
        for(int i=0;i<len1;i++)
            printf("%d",B[i]);
    }