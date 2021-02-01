
const int mod = 1e9+7;
int n;
int dp[510][510];

int go(int pos,int k)
{
    if(k==0)
    {
        if(pos==0)
            return 1;
        return 0;
    }

    int &re = dp[pos][k];
    if(re!=-1)
        return re;
    re = 0;
    re = go(pos,k-1)%mod;
    if(pos+1<=n)
        re = (re % mod) + (go(pos+1,k-1)%mod);
    re%=mod;
    if(pos-1>=0)
        re = (re % mod) + (go(pos-1,k-1)%mod);
    re%=mod;
    return re;
}

class Solution {
public:
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof dp);
        n = min(505,arrLen-1);
        return go(0,steps)%mod;
    }
};
