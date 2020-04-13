#include<stdio.h>
int main()
    {
        int cash;
        printf("Enter amount to be withdrawn: ");
        scanf("%d",&cash);
        printf("Cashier gives you %d currency notes of 10\nOR\n",cash/10);
        printf("%d currency notes of 50\nOR\n",cash/50);
        printf("%d currency notes of 100\n",cash/100);
        return 0;
    }