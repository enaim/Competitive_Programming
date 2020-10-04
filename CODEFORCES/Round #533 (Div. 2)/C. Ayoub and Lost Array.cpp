#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll M = 1e9+7;
ll dp[200010][5];
ll x[5];

int main()
{
    ll l,r,n,i,j,k;
    while(3==scanf("%lld%lld%lld",&n,&l,&r))
    {
        x[0] = r/3 - (l-1)/3;
        x[1] = ((r+2)/3) - ((l+1)/3);
        x[2] = (r+1)/3 - (l)/3;
        dp[0][0]=1;

        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                if(dp[i][j])
                {
                    for(k=0;k<3;k++)
                    {
                        dp[i+1][(j+k)%3]+=(dp[i][j]*x[k]);
                        dp[i+1][(j+k)%3]%=M;
                    }
                }
            }
        }
        printf("%lld\n",dp[n][0]);
    }

    return 0;
}
