int N;
int dp[6][52];
int go(int pos, int k)
{
    if(N==k)
  	    return 1;
    int &re = dp[pos][k];
    if(re!=-1)
  	    return re;
    re = 0;
    for(int i=pos;i<5;i++)
    {
  	    re+=go(i,k+1);
    }
    return re;
}

class Solution {
public:
    int countVowelStrings(int n) {
        N = n;
        int ans = 0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<5;i++)
        {
        	memset(dp,-1,sizeof dp);
        	ans += go(i,1);
        }

        return ans;
    }
};
