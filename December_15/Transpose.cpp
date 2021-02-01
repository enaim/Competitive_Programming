#include<stdio.h>


int main()
{
    int i,r;
    int a[10];
    int b[10];
    int c[10];

    while(scanf("%d",&r)==1)
    {
        for(i=0;i<r;i++)
                scanf("%d",&a[i]);

        for(i=r-1;i>-1;i--)
                b[r-i-1]=a[i];

        for(i=0;i<r;i++)
            {
                c[i] = a[i] + b[i];
                printf("%d ",c[i]);
            }
    }

    return 0;
}
