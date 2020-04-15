#include<stdio.h>

void rule5(int *C, int n)
    {
        //remove elements that can be formed by squaring any other element
        int i, j, k, l;
        for(i = 0 ; i < n ; i++)
            {
                for(j = 0 ; j < n-1 ; j++)
                    if(C[j] == C[i]*C[i])
                        {
                            for(l = j; l < n; l++)
                                C[l] = C[l+1];
                            n--;
                        }
            }
            for(i = 0 ; i < n ; i++)
                printf("%d ", C[i]);
            printf("\n");
        }

void rule4(int *B, int n)
    {
        //remove elements that can be formed by adding two elements
        int i, j, k, l, flag = 0;
        int C[n],c_index = 0;
        l = n;
        for(i = 0 ; i < n ; i++)
            {
                flag = 0;
                for(j = 0 ; j < n-1 ; j++)
                    {
                        if(j != i)
                        {
                            for(k = j+1 ; k < n ; k++)
                            {
                                if(B[i] == B[j] + B[k])
                                    flag = 1;  
                            }
                        }
                    }
                if(flag == 0)
                    C[c_index++] = B[i];
                else
                    l--;
            }
        for(i = 0 ; i < l ; i++)
            printf("%d ", C[i]);
        printf("\n");
        rule5(C,l);
    }

void rule3(int *B, int n)
    {
        //array elements will not comprise of element 0
        int i, j;
        for(i = 0 ; i < n ; i++)
            {
                if(B[i] == 0)
                    {
                        for(j = i; j < n; j++)
                            B[j] = B[j+1];
                        n--;
                    }
            }
        for(i = 0 ; i < n ; i++)
                printf("%d ", B[i]);
        printf("\n");
        rule4(B,n);
    }

void rule1(int *B, int n)
    {
        //remove duplicates
        int i, j, k;
        for(i = 0; i < n; i++)
        {
            for(j = i+1; j < n;)
            {
                if(B[j] == B[i])
                {
                    for(k = j; k < n; k++)
                    {
                        B[k] = B[k+1];
                    }
                    n--;
                }
                else
                {
                    j++;
                }
            }
        }
        for(i = 0 ; i < n ; i++)
                printf("%d ", B[i]);
        printf("\n");
        rule3(B,n);
    }

void rule2(int *B, int n)
    {
        //only single digit, multi digit result to digit sum
        int i;
        for(i = 0 ; i < n; i++)
        {
            if(B[i]>9)
                {
                    B[i] = (B[i] % 9 == 0) ? 9 : (B[i] % 9); 
                }
        }
        for(i = 0 ; i < n ; i++)
            printf("%d ", B[i]);
        printf("\n");
        rule1(B,n);
    }

int main()
    {
        int a[10] = {1,2,3,4,5,1,2,2,0,14}, n = 10;
        rule2(a,n);
    }