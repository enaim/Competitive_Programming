class Solution {
public:
    int constrainedSubsetSum(vector<int>& ar, int k) {
        int n = ar.size(),i,mx=ar[0],val;
        deque<pair<int,int>>dq;
        for(i=0;i<n;i++)
        {
            val = ar[i];
            while(!dq.empty() && dq.front().first<i-k)
                dq.pop_front();

            if(!dq.empty() && dq.front().second>0)
                val = val + dq.front().second;

            mx = max(val,mx);

            while(!dq.empty() && dq.back().second<val)
                dq.pop_back();

            dq.push_back(make_pair(i,val));
        }
        return mx;
    }
};
