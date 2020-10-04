class Solution {
public:
    bool kLengthApart(vector<int>& vec, int k) {
        int i,n=vec.size(),last=-1;
        for(i=0;i<n;i++)
        {
            if(vec[i]==1 && last==-1)
                last = i;
            else if(vec[i]==1 && last!=-1)
            {
                if(i-last-1<k)
                    return false;
                last = i;
            }
        }
        return true;
    }
};
