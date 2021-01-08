class Solution {
public:
    int maxResult(vector<int>& ar, int k) {
        int i, n = ar.size();
        int dp[100010]={0};
        deque<int>dq;
        dp[0]=ar[0];
        dq.push_back(0);
        for(i=1;i<n;i++)
        {
            while(!dq.empty() && dq.front()+k<i)
                dq.pop_front();
            dp[i]=dp[dq.front()]+ar[i];
            while(!dq.empty() && dp[dq.back()]<=dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return dp[n-1];
    }
};
