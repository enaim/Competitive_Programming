#include<stdio.h>


int main()
{
    int a[10][10];
    int b[10][10];
    int c[10][10];
    int R,C,i,j,n,f,sum;

    while(scanf("%d%d",&R,&C)==2)
    {
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
                scanf("%d",&a[i][j]);

        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
            {
                sum=0;
                n=a[i][j];
                while(0<n || n<0)
                {
                    f=n%10;
                    n/=10;
                    sum+=f;
                }
                   b[i][j]=sum;
            }

        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
                printf("%d ",b[i][j]);
            printf("\n");
        }

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
