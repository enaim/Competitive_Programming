class Solution {
public:
    int numDecodings(string s) {
        int dp[110];
        memset(dp,0,sizeof dp);
        int len = s.size();
        dp[len]=1;
        for(int i=len-1;i>=0;i--)
        {
          if(s[i]=='0')
            dp[i]=0;
          else if(s[i]=='1')
            dp[i]=dp[i+1]+dp[i+2];
          else if(s[i]=='2')
          {
            dp[i] = dp[i+1];
            if(len>i+1 && s[i+1]<='6')
                dp[i] += dp[i+2];
          }
          else
            dp[i]=dp[i+1];
        }
        return dp[0];
    }
};
