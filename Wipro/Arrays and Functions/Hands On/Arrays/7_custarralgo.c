#include<stdio.h>
int main()
    {
        int a[20], i, sum = 0, count = 0;

        printf("Enter 20 numbers\n");
        for(i = 0 ; i < 20 ; i++)
            scanf("%d",&a[i]);
        
        for(i = 0 ; i < 20 ; i++)
            {
                if(a[i]%2==0)
                    {
                        count++;
                        sum += a[i];
                    }
            }
        printf("The count of even numbers in array is: %d\n",count);
        printf("Sum of all values of all the even numbers is: %d\n",sum);
         
        return 0;
    }