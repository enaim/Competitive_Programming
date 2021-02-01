#include<stdio.h>

int n,k;
int ar[100];
int Q[10];

void go(int start,int depth)
{
    int i;
    if(depth==k+1)
    {
        for(i=1;i<=k;i++)
        {
            if(i==1)
                printf("%d",Q[i]);
            else
                printf(" %d",Q[i]);
        }
        printf("\n");
        return;
    }
    for(i=start;i<n-(k-depth);i++)
    {
        Q[depth]=ar[i];
        go(i+1,depth+1);
    }
}

int main()
{
    while(scanf("%d%d",&n,&k)==2 && n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&ar[i]);
        go(0,1);
        printf("\n");
    }
    return 0;
}
