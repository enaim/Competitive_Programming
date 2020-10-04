#include<stdio.h>


int main()
{
    freopen("tabs.in","r",stdin);
    int n,k,tks;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&n,&k);
        if(n==1)
            printf("0\n");
        else if(k==1 || k==n)
            printf("1\n");
        else
            printf("2\n");
    }

    return 0;
}
