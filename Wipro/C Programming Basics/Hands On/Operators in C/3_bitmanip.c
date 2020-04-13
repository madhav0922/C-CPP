#include<stdio.h>

int main()
    {
        int m, n, k, set_bit, clear_bit, show_bit;
        printf("Enter a number\n");
        scanf("%d",&n);
        m = n;
        printf("Enter bit position to be manipulated\n");
        scanf("%d",&k);
        set_bit = n | (1<<(k-1));
        printf("%d with %d-th bit Set: %d\n",n,k,set_bit);
        n = m;
        clear_bit = n & (~(1<<(k-1)));
        printf("%d with %d-th bit cleared: %d\n",n,k,clear_bit);
        n = m;
        show_bit = (n >> (k-1)) & 1;
        printf("%d bit position in %d : %d\n",k,n,show_bit);
        return 0;     
    }