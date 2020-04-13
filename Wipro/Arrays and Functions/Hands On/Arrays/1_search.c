#include<stdio.h>

int main()
    {
        int n, ele, flag = 0, i, j;
        printf("Enter the size of an array\n");
        scanf("%d",&n);

        int a[n];
        
        printf("Enter the elements of an array\n");
        for(i = 0 ; i < n ; i++)
            scanf("%d",&a[i]);
        printf("Enter the element to search: ");
        scanf("%d",&ele);
        for(j = 0 ; j < n ; j++)
            {
                if(a[j]==ele)
                    {
                        flag = 1;
                        break;
                    }
            }
        if(flag == 1)
            printf("***Element %d found at its index %d***\n",ele,j);
        else
            printf("!!!Element not found!!!\n");
        return 0;
    }