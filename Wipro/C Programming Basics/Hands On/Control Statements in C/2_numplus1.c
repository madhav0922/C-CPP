#include<stdio.h>
#include<math.h>

int main()
    {
        int m, n, digit, new_num, digit_count = 0;
        printf("Enter a number : ");
        scanf("%d",&n);
        while(n>0)
            {
                digit = n % 10;
                n = n / 10;
                if(digit == 9)
                    digit = 0;
                else
                    digit++;

                new_num = new_num + digit * pow(10,digit_count);
                digit_count++;
            }
        
        printf("New Number by adding one to each digit is : %d\n",new_num);
    }