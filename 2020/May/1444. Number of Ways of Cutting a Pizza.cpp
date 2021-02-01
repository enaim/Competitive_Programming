class Solution {
    int n,m;
    int g[52][52];
    int mod = 1e9+7;
    int dp[52][52][12];

    int go(int r,int c,int rest)
    {
        int &re = dp[r][c][rest];
        if(re!=-1)
            return re;
        re = 0;
        if(rest==0)
        {
            if(g[r][c])
                re = 1;
            else
                re = 0;
            return re;
        }
        int i;
        for(i=r+1;i<n;i++)
        {
            if(g[r][c]-g[i][c]>0 && g[i][c]>=rest)
                re = ((re%mod)+(go(i,c,rest-1)%mod))%mod;
        }
        for(i=c+1;i<m;i++)
        {
            if(g[r][c]-g[r][i]>0 && g[r][i]>=rest)
                re = ((re%mod)+(go(r,i,rest-1)%mod))%mod;
        }
        return re;
    }

public:
    int ways(vector<string>& pizza, int rest) {
        int i,j,k;
        n = pizza.size();
        m = pizza[0].size();
        memset(g,0,sizeof 0);
        memset(dp,-1,sizeof dp);
        for(i=n-1;i>=0;i--)
            for(j=m-1;j>=0;j--)
            {
                g[i][j]=g[i][j+1];
                for(k=i;k<n;k++)
                    g[i][j]+=(pizza[k][j]=='A');
            }
        return go(0,0,rest-1);
    }
};
