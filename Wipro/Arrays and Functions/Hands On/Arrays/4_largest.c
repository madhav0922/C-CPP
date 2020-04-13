
#include<stdio.h>

int main()
    {
        int n, i;
        printf("Enter the size of an array\n");
        scanf("%d",&n);

        int a[n], max;

        printf("Enter %d numbers\n",n);
        for(i = 0 ; i < n ; i++)
            scanf("%d",&a[i]);
        
        max = a[0];
        for(i = 0 ; i < n ; i++)
            {
                if(max < a[i])
                    max = a[i];
            }
            
        printf("Largest element is %d\n",max);
        return 0;
    }