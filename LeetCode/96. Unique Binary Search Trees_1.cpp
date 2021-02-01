long long dp[1000];

class Solution {
public:
    int numTrees(int n) {
        dp[0]=dp[1]=1;
        for(int i=2;i<=n+2;i++)
        {
            dp[i]=0;
            for(int j=0;j<i;j++)
                dp[i] += dp[j]*dp[i-j-1];
        }
        return dp[n];
    }
};
