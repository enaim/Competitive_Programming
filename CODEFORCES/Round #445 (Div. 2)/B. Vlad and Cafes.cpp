#include<bits/stdc++.h>
using namespace std;


int main()
{
    int ar[200010],br[200010],ans,n,x,i;
    while(scanf("%d",&n)==1)
    {
        memset(br,-1,sizeof br);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        for(i=n-1;i>=0;i--)
        {
            x = ar[i];
            if(br[x] == -1)
            {
                br[x] = 1;
                ans = x;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
