long long m = 1e9+7;
long long dp[5010][3];
int N;

long long go(int pos,int k)
{
    if(pos==N)
        return 1;
    long long &re = dp[pos][k];
    if(re!=-1)
        return re;

    re = 2LL * go(pos+1,1);
    re %= m;

    if(k==2)
        re = re + 3LL * go(pos+1,2);
    else
        re = re + 2LL * go(pos+1,2);
    re %= m;
    return re;
}

class Solution {
public:
    int numOfWays(int n) {
        N = n;
        memset(dp,-1,sizeof dp);
        long long ans1 = 6LL * go(1,1);
        ans1 %= m;
        long long ans2 = 6LL * go(1,2);
        ans2 %= m;
        return (ans1+ans2)%m;
    }
};
