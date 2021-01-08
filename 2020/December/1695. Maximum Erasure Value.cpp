class Solution {
public:
    int maximumUniqueSubarray(vector<int>& ar) {
        map<int,int>mp;
        int sum = 0, mx = -1;
        int i,j,x,n = ar.size();
        int last = 0;
        for(i=0;i<n;i++)
        {
            if(mp[ar[i]]==0)
                mp[ar[i]]=i+1,sum+=ar[i];
            else
            {
                int x = mp[ar[i]];
                for(j=last;j<x;j++)
                    mp[ar[j]]=0,sum-=ar[j];
                last = x;
                mp[ar[i]]=i+1;
                sum+=ar[i];
            }
            mx = max(mx,sum);
        }
        return mx;
    }
};
