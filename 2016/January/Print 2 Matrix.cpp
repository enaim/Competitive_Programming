#include<stdio.h>


int main()
{
    int a[10][10];
    int b[10][10];
    int R,C,i,j,k,n;

    while(scanf("%d%d",&R,&C)==2)
    {

        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
                scanf("%d",&a[i][j]);


        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
                scanf("%d",&b[i][j]);

        for(i=0;i<R;i++)
        {
            printf("| ");
                for(j=0;j<C;j++)
                {
                     printf("%d ",a[i][j]);
                }
            printf("| \t| ");

            for(j=0;j<C;j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("|\n");
        }
    }

    return 0;
}
