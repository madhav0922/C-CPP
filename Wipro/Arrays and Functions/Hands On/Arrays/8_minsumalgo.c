#include<stdio.h>
int main()
    {
        int a[5], i, j, min;

        printf("Enter 5 numbers\n");
        for(i = 0 ; i < 5 ; i++)
            scanf("%d",&a[i]);
        
        min = a[0];
        for(i = 0 ; i < 5 ; i++)
            {
                for(j = 0 ; j < 4 ; j++)
                    if(a[i] != a[j]+a[j+1] && a[i]< min)
                        min = a[i];
            }
        printf("%d is the smallest integer that cannot be formed by sum of other two in array\n",min);
        return 0;
    }