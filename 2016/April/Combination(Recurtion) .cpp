#include <stdio.h>
#include <string.h>
#include <math.h>

int n,r;
int Q[1000];

void comb(int depth,int start)
{
    if(depth==r)
    {
        for(int j=0;j<r;j++)
            printf("%d ",Q[j]);
        printf("\n");
    }


    for(int i=start;i<=n;i++)
    {
        Q[depth]=i;
        comb(depth+1,i+1);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&r))
    {
        comb(0,1);
    }

    return 0;
}

