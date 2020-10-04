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



        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
                b[C-j-1][i] = a[i][j];
        }


        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
                printf("%d ",b[i][j]);
            printf("\n");
        }


    }

    return 0;
}


