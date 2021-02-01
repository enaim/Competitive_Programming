long long dp[1010];
long long Solve(int n)
{
    if(n<=1)
        return 1;
    long long &sum = dp[n];
    if(sum!=-1)
        return sum;
    sum = 0LL;
    for(int i=1;i<=n;i++)
        sum += Solve(i-1)*Solve(n-i);
    return sum;
}

class Solution {
public:
    int numTrees(int n) {
        memset(dp,-1,sizeof dp);
        return Solve(n);
    }
};
