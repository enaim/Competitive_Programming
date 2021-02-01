class Solution {
public:
    int countTriplets(vector<int>& ar) {
        int n = ar.size();
        int x, i, t, j, k, cnt=0;
        for(i=0;i<n;i++)
        {
            x = t = 0;
            for(j=i;j<n;j++)
            {
                x^=ar[j];
                t = 0;
                if(x==0)
                for(k=i;k<j;k++)
                {
                    t^=ar[k];
                    if(t == (x^t))
                        cnt++;
                }
            }
        }
        return cnt;
    }
};
