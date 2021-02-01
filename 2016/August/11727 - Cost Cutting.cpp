#include<stdio.h>


int main()
{
    int a,b,c,t,x,ks=1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);

        if((a>b && b>c) || (a<b && b<c) )
            x = b;
        else if((b>a && a>c) || (b<a && a<c))
            x = a;
        else
            x = c;

        printf("Case %d: %d\n",ks++,x);
    }

    return 0;
}
