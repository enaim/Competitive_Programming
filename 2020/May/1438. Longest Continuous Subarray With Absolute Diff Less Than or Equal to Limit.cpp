class Solution {
public:
    int longestSubarray(vector<int>& ar, int limit) {
        deque<int>minQue;
        deque<int>maxQue;
        int i, n = ar.size();
        int ans = 0, s = 0, e = 0;
        for(i=0;i<n;i++)
        {
            e = i;
            int val = ar[i];

            while(!minQue.empty() && ar[minQue.back()]>=val)
                minQue.pop_back();
            minQue.push_back(i);

            while(!maxQue.empty() && ar[maxQue.back()]<=val)
                maxQue.pop_back();
            maxQue.push_back(i);

            int mn = ar[minQue.front()];
            int mx = ar[maxQue.front()];

            if(mx-mn<=limit)
            {
                ans = max(ans,e-s+1);
            }
            else
            {
                s++;
                if(minQue.front()<s)
                    minQue.pop_front();
                if(maxQue.front()<s)
                    maxQue.pop_front();
            }
        }
        return ans;
    }
};
