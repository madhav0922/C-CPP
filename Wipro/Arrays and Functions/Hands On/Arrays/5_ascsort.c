#include<stdio.h>
int main()
    {
        int n, i, j;
        printf("Enter the size of an array\n");
        scanf("%d",&n);

        int a[n], temp;

        printf("Enter %d numbers\n",n);
        for(i = 0 ; i < n ; i++)
            scanf("%d",&a[i]);
        
        for(i = 0; i < n-1; i++)
            {
                for(j = i+1 ; j < n ; j++)
                    {
                        if(a[i]>a[j])
                            {
                                temp = a[i];
                                a[i] = a[j];
                                a[j] = temp;
                            }
                    }
            }
        printf("The numbers arranged in ascending order are given below\n");
        for(i = 0 ; i < n ; i++)
            printf("%d\n",a[i]);  
        return 0;
    }