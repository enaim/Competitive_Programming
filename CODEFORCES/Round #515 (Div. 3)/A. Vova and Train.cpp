#include<stdio.h>


int main()
{
    int x,y,z,ans,a,b,c,d,tks;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        x = a/b;
        y = d/b;
        z = (c-1)/b;
        ans = x -(y-z);

        printf("%d\n",ans);
    }

    return 0;
}
