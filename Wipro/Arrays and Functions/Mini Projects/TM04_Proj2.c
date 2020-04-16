#include<stdio.h>

int identifyHeavy(int M[3][3])
    {
        int corner_sum = 0, center_sum = 0;
        corner_sum = M[0][0] + M[0][2] + M[2][0] + M[2][2];
        center_sum = M[0][1] + M[1][0] + M[1][2] + M[2][1];

        if(corner_sum > center_sum)
            return 1;
        else if(center_sum > corner_sum)
            return 2;
        else
            return 3;
    }

int main()
    {
        int M[3][3] = {{1,5,7},{3,9,8},{2,6,4}};
        printf("Enter unique elements into 3x3 matrix\n");

        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                scanf("%d",&M[i][j]);

        printf("\n%d\n",identifyHeavy(M));
        return 0;
    }