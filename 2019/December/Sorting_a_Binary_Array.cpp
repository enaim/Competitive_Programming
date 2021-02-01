#include<bits/stdc++.h>
using namespace std;

int ar[200010];

int main()
{
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        int zero = 0;
        for(i=0;i<n;i++)
            if(!ar[i])
                zero++;

        if(zero==0 || zero==n)
        {
            printf("0\n");
            continue;
        }

        long long sum=0;
        int cnt = 0;
        for(i=0;i<n;i++)
        {
            if(ar[i]==0 && cnt == i)
            {
                cnt++;
                continue;
            }
            if(ar[i]==0)
            {
                sum+=(i-cnt);
                cnt++;
            }
        }
        printf("%lld\n",sum);
    }

    return 0;
}
