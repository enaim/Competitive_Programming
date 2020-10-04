#include<stdio.h>


int main()
{
    int a[100],d,n,i,j,c;
    while(2==scanf("%d%d",&n,&d))
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        c = 0 ;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)

                if(a[i]+a[j]==d)
                    {
                        printf("%d-%d\t",a[i],a[j]);
                        c++;
                    }
                printf("\n");
        }
            printf("count : %d",c);
    }
    return 0;
}

