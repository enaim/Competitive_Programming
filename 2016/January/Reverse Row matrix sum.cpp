#include<stdio.h>


int main()
{
    int a[10][10];
    int b[10][10];
    int c[10][10];
    int R,C,i,j;

    while(scanf("%d%d",&R,&C)==2)
    {
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
                scanf("%d",&a[i][j]);

        for(i=R-1;i>-1;i--)
            for(j=C-1;j>-1;j--)
                b[R-i-1][C-j-1]=a[i][j];            ///reverse row

        for(i=0;i<R;i++)
            for(j=C-1;j>-1;j--)
                b[i][C-j-1]=a[i][j];

        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
                c[i][j] = a[i][j] + b[i][j];

        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
                printf("%d ",c[i][j]);
            printf("\n");
        }
    }

    return 0;
}

