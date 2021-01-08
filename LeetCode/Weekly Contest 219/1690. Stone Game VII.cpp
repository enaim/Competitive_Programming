int n;
int ar[1010];
int dp[1010][1010];
int go(int i, int j, int sum)
{
    if(i==j)
        return 0;
    int &re = dp[i][j];
    if(re!=-1)
        return re;
    re = max( (sum - ar[i] - go(i+1,j,sum-ar[i]))  ,  (sum - ar[j] - go(i,j-1,sum-ar[j])) );
    return re;
}

class Solution {
public:
    int stoneGameVII(vector<int>& vec) {
        memset(dp,-1,sizeof dp);
        n = vec.size();
        int sum = 0;
        for(int i=0;i<n;i++)
            sum+=vec[i],ar[i]=vec[i];
        return go(0,n-1,sum);
    }
};
