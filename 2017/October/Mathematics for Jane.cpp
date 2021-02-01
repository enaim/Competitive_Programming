#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,ar[30],i,j,x,cnt,tks;
    map<int,int>mp;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        cnt = 0;
        mp.clear();
        for(i=0;i<n;i++)
        {

            scanf("%d",&ar[i]);
            if(mp[ar[i]] == 0)
            {
                mp[ar[i]] = 1;
                cnt++;
            }
        }

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                x = ar[i]+ar[j];
                if(mp[x]==0)
                {
                    mp[x]=1;
                    cnt++;
                }
            }
        printf("%d\n",cnt);
    }

    return 0;
}
