class Solution {
public:
    int maxOperations(vector<int>& ar, int k) {
        int n = ar.size(),i,j,cnt;
        sort(ar.begin(),ar.end());
        i = 0;
        j = n-1;
        cnt = 0;
        while(i<j)
        {
            if(ar[i]+ar[j]==k)
            {
                cnt++;
                i++;
                j--;
            }
            else if(ar[i]+ar[j]<k)
                i++;
            else
                j--;
        }
        return cnt;
    }
};
