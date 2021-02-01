#include<bits/stdc++.h>
using namespace  std;

int par[200010];

int main()
{
    int n,ar[200010],i,x;
    while(1==scanf("%d",&n))
    {
        for(i=2;i<=n;i++)
        {
            scanf("%d",&x);
            par[i]=x;
        }
        x = n;
        int cnt = 0;
        ar[0]=n;
        while(x!=1)
        {
            cnt++;
            ar[cnt]=par[x];
            x = par[x];
        }
        for(i=cnt;i>=0;i--)
            printf("%d ",ar[i]);
        printf("\n");
    }

    return 0;
}
