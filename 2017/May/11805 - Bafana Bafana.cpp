#include<stdio.h>


int main()
{
    int n,k,p,x,a,b,tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d",&n,&k,&p);
        if(p>n)
        {
            p = p%n;
            a = k+p;
        }

        else
            a = k+p;

        if(a>n)
                printf("Case %d: %d\n",ks++,a-n);
        else
            printf("Case %d: %d\n",ks++,a);
    }

    return 0;
}
