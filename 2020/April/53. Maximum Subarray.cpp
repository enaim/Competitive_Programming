class Solution {
public:
    int maxSubArray(vector<int>& ar) {
        int mx = ar[0];
        int sum = ar[0];
        for(int i=1;i<ar.size();i++)
        {
            if(sum<=0)
                sum = ar[i];
            else
                sum += ar[i];
            mx = max(sum,mx);
        }
        return mx;
    }
};
