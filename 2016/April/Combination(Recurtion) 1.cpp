#include <stdio.h>
#include <string.h>
#include <math.h>

int ar[13];
int q[13];
int n,r;

void lotto(int depth,int start)
{
    if(depth==r)
    {
        for(int i=0;i<r;i++)
            printf("%d ",q[i]);
        printf("\n");
        return;
    }

    for(int i=start;i<n;++i)
    {
        q[depth] = ar[i];
        lotto(depth+1,i+1);
    }
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j;

    while(2==scanf("%d%d",&n,&r))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        lotto(0,0);
    }

    return 0;
}

