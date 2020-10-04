#include<stdio.h>


int main()
{
    freopen("in.txt","r",stdin);


    int a[10][10];
    int b[10][10];
    int c[10][10];
    int R,C,i,j,k,n;
    printf("| 2 3 3 |     | 2 3 3 |\n");
    printf("| 2 3 3 |  +  | 2 3 3 |\n");
    printf("| 2 3 3 |     | 2 3 3 |\n");

    while(scanf("%d%d",&R,&C)==2)
    {
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
                scanf("%d",&a[i][j]);

        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
                scanf("%d",&b[i][j]);

        while(scanf("%d",&n)==1 && n)
        {
            if(n==1)
            {   for(i=0;i<R;i++)
                    for(j=0;j<C;j++)
                        c[i][j] = a[i][j] + b[i][j];
            }
            else if(n==2)
            {
                for(i=0;i<R;i++)
                    for(j=0;j<C;j++)
                        c[i][j] = a[i][j] - b[i][j];

            }
            else if(n==3)
            {
                for (i = 0; i< R; i++)
                {
                    for (j = 0; j < C; j++)
                    {
                        int sum=0;
                        for (k = 0; k < R; k++)
                        {
                            sum += a[i][k]*b[k][j];
                        }

                        c[i][j] = sum;

                    }
                }

            }

            for(i=0;i<R;i++)
            {
                for(j=0;j<C;j++)
                    printf("%d ",c[i][j]);
                printf("\n");
            }
            printf("\n\n\n\n");
        }

    }

    return 0;
}

