#include<stdio.h>

int main()
    {
        int n, i;
        printf("Enter the size of an array\n");
        scanf("%d",&n);

        float a[n], sum=0;

        printf("Enter %d numbers\n",n);
        for(i = 0 ; i < n ; i++)
            scanf("%f",&a[i]);
        for(i = 0 ; i < n ; i++)
            sum += a[i];

        printf("Sum of all elements in array is %.0f\n",sum);
        printf("Average of all input numbers = %.2f\n",(sum/n));
        return 0;
    }