#include<stdio.h>


int main()
{
    int r,i,c,j;
    int a[10][10];
    int b[10][10];
    int d[10][10];

    while(scanf("%d%d",&r,&c)==2)
    {
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                scanf("%d",&a[i][j]);

         for(i=r-1;i>-1;i--)
            for(j=r-1;j>-1;j--)
                {
                b[r-i-1][c-j-1]=a[i][j];
                printf("%d %d\n",b[r-i-1][c-j-1]);
                }


        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                {
                d[i][j] = a[i][j] + b[i][j];
                printf("%d %d \n",d[i][j]);
                }

    }

    return 0;
}

