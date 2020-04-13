#include<stdio.h>

int main()
    {
        int row, col, i, j;
        printf("Enter the number of rows and columns of matrix\n");
        scanf("%d%d",&row,&col);

        int M[row][col], T[col][row];

        printf("Enter the elements of matrix\n");
        
        for(i = 0 ; i < row ; i++)
            {for(j = 0 ; j < col; j++)
                scanf("%d",&M[i][j]);
            }

        for(i = 0 ; i < col ; i++)
            for(j = 0 ; j < row; j++)
                T[i][j] = M[j][i];

        printf("Transpose of entered matrix is\n");
        
        for(i = 0 ; i < col ; i++)
            {
                for(j = 0 ; j < row; j++)
                    printf("%d    ",T[i][j]);
                printf("\n");
            }

        return 0;
    }