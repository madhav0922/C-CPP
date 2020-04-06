#include<stdio.h>
#include<stdlib.h>

void row_numbers(int n)
    {
        int i,j,k,temp;
        j=1;
        for(i = 1; i <= (2*n)-1; i=i+2)
            {
                //print spaces
                for(k = n-1 ; k >= j; k--)
                    printf(" ");
                
                //print pattern
                temp = i;
                while(temp>0)
                    {
                        printf("%d",j);
                        temp--;
                    }
                j++;

                printf("\n");
            }
    }

void row_numbers_backwards(int n)
    {
        int i,j,k,temp;
        j=n;
        for(i = 1; i <= (2*n)-1; i=i+2)
            {
                //print spaces
                for(k = 1 ; k < j; k++)
                    printf(" ");

                //print pattern    
                temp = i;
                while(temp>0)
                    {
                        printf("%d",j);
                        temp--;
                    }
                j--;
                
                printf("\n");
            }
    }

void up_down_numbers(int n)
    {
        int i,j,k,temp;
        for(i = 1; i <= n ; i++)
            {
                //print spaces
                for(k = i ; k < n; k++)
                    printf(" ");

                //print pattern
                temp = i;
                j=1;
                printf("%d",j);
                while(j<temp)
                    {
                        printf("%d",++j);
                    }
                while(temp<=j && temp>1)
                    printf("%d",--temp);
                
                printf("\n");
            }
    }

void up_numbers_down_alpha(int n)
    {
        int i,j,k,temp;
        for(i = 1; i <= n ; i++)
            {
                //print spaces
                for(k = i ; k < n; k++)
                    printf(" ");

                //print pattern
                temp = i;
                j=1;
                printf("%d",j);
                    
                    while(j<temp)
                        {
                            printf("%d",++j);
                        }
                    while(temp<=j && temp>1)
                        printf("%c",--temp+64);
                
                printf("\n");
            }
    }

void alpha_num_alter(int n)
    {
        int i,j,k,temp;
        for(i = 1; i <= n ; i++)
            {
                //print spaces
                for(k = i ; k < n; k++)
                    printf(" ");
                
                //print pattern
                temp = i;
                j=1;
                printf("%c",j+64);
                    while(j<temp)
                        {
                            j++;
                            if(j%2==0)
                                printf("%d",j);
                            else
                                printf("%c",j+64);
                        }
                    while(temp<=j && temp>1)
                        {
                            if(temp%2!=0)
                                printf("%d",--temp);
                            else
                                printf("%c",--temp+64);
                            
                        }
                
                printf("\n");
            }
            
    }

void consecutive_series(int n)
    {
        int i,j,k,p;
        p=1;
        for(i=1;i<=n;i++)
            {
                //print spaces
                for(k = n ; k > i ; k--)
                    printf(" ");

                //print pattern
                for(j = 1 ; j <= (2*i)-1 ; j++)
                    {
                        if(p>9)
                            p = 0;
                        printf("%d",p++);
                    }

                printf("\n");
            }
    }

void row_no_up_down(int n)
    {
        int i,j,k,l;
        for(i = 1 ; i <= n ; i++)
            {
                j = i;
                //print spaces
                for(k = n ; k > i ; k--)
                    printf(" ");

                //print pattern
                for(l = i; l < i+i ; l++)
                    {
                        if(j>9)
                            j=1;
                        printf("%d",j++);
                    }
                j--;
                for(l = i+i ; l > i+1 ; l--)
                    {
                        j--;
                        if(j<1)
                            j=9;
                        printf("%d",j);
                    }

                printf("\n");
            }
    }

void diamond_alpha_numeric(int n)
    {
        int i,j,k,temp;

        //print first half
        j=1;
        for(i = 1; i <= (2*n)-1; i=i+2)
            {
                //print spaces
                for(k = n-1 ; k >= j; k--)
                    printf(" ");

                //print pattern
                temp = i;
                while(temp>0)
                    {
                        printf("%d",j);
                        temp--;
                    }
                j++;
                
                printf("\n");
            }

        //print second half
        j = j-2;
        for(i = (2*(n-1)-1) ; i >= 1 ; i=i-2)
            {
                //print spaces
                for(k = n-1 ; k >= j; k--)
                    printf(" ");

                //print pattern
                temp = i;
                while(temp>0)
                    {
                        printf("%c",j+64);
                        temp--;
                    }
                j--;
                
                printf("\n");
            }
    }

void diamond_alpha_star(int n)
    {
        int i,j,k,temp,new_j;
        j=1;
        //print first half
        for(i = 1; i <= (2*n)-1; i=i+2)
            {
                //print spaces
                for(k = j ; k <= n-1 ; k++)
                    printf(" ");

                //print pattern
                j=1;
                temp = 1;
                while(temp<=i)
                    {
                        if(temp<=((i/2)+1))
                            printf("%d",j++);
                        else
                            printf("*");
                        temp++;
                    }

                printf("\n");
            }

        //print second half
        new_j = j-2;
        for(i = (2*(n-1)-1) ; i >= 1 ; i=i-2)
            {
                j = new_j--;
                //print spaces
                for(k = n-1 ; k >= j; k--)
                    printf(" ");

                //print pattern
                temp = i;
                while(temp>0)
                    {
                        if(temp>((i/2)+1))
                            printf("*");
                        else
                            printf("%d",j--);
                        temp--;
                    }
                
                printf("\n");
            }
    }

int main()
    {
        int choice,ROW_LEVEL = 5;
        while(1)
        {
        printf("---------------\n");
        printf("** MAIN MENU **\n");
        printf("---------------\n");
        printf("1. Row Numbers\n");
        printf("2. Row Numbers Backwards\n");
        printf("3. Up Down Numbers\n");
        printf("4. Up Numbers Down Alphabets\n");
        printf("5. Alpha Numeric Alternate\n");
        printf("6. Consecutive Numbers\n");
        printf("7. Row Number Up Down\n");
        printf("8. Diamond Alpha Numeric\n");
        printf("9. Diamond Alpha Star\n");
        printf("10.SET ROW_LEVEL\n");
        printf("0. EXIT\n");
        printf("\nEnter your option(1 to 10) (0 to EXIT): ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
            {
                case 1: row_numbers(ROW_LEVEL);
                        break;
                case 2: row_numbers_backwards(ROW_LEVEL);
                        break;
                case 3: up_down_numbers(ROW_LEVEL);
                        break; 
                case 4: up_numbers_down_alpha(ROW_LEVEL);
                        break; 
                case 5: alpha_num_alter(ROW_LEVEL);
                        break;
                case 6: consecutive_series(ROW_LEVEL);
                        break;
                case 7: row_no_up_down(ROW_LEVEL);
                        break;
                case 8: diamond_alpha_numeric(ROW_LEVEL);
                        break;
                case 9: diamond_alpha_star(ROW_LEVEL);
                        break;
                case 10: printf("Current Row Level = %d\n",ROW_LEVEL);
                         printf("Set new row level (1 to 15): ");
                         scanf("%d",&ROW_LEVEL);
                         printf("New Row Level = %d\n",ROW_LEVEL);
                         break;
                case 0: exit(0);
            }
        printf("\nPress any key to continue...\n");
        getchar();
        getchar();
        }
    }