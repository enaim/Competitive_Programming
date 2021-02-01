class Solution {
public:
    int longestSubsequence(vector<int>& ar, int d) {
        int n = ar.size(),i;
        int flag[50010];
        for(i=0;i<50010;i++)
            flag[i] = 0;
        i=n-1;
        int cnt = 1;
        while(i>=0)
        {
            if(ar[i]<0)
            {
                int x = ar[i]+d;
                if(x<0)
                    flag[abs(ar[i])+30000]=1+flag[abs(x)+30000];
                else
                    flag[abs(ar[i])+30000]=1+flag[abs(x)];
            }
            else
            {
                int x = ar[i]+d;
                if(x<0)
                    flag[abs(ar[i])]=1+flag[abs(x)+30000];
                else
                    flag[abs(ar[i])]=1+flag[abs(x)];
            }
            i--;
        }
        int mx = 1;
        for(i=0;i<50010;i++)
            mx = max(mx,flag[i]);
        return mx;
    }
};
