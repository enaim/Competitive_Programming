class Solution {
public:
    int maxScore(vector<int>& vec, int k) {
        int n = vec.size();
        int ar[n],i;
        for(i=0;i<n;i++)
            ar[i]=0;
        ar[0]=vec[0];
        for(i=1;i<n;i++)
            ar[i]=vec[i]+ar[i-1];
        int mx = ar[k-1];
        if(k<n)
            mx = max(ar[k-1],ar[n-1]-ar[n-1-k]);
        for(i=0;i<k-1;i++)
            mx = max(mx,ar[i]+ar[n-1]-ar[n-1-(k-i-1)]);
        return mx;
    }
};
