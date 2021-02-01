class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int flag[1100]={0};
        int cnt = 0;
        int i = 0;
        int j = 0;
        int sz = pushed.size();
        while(cnt != sz && i<sz && j<sz)
        {
            if(pushed[i]==popped[j])
            {
                if(flag[i]==1)
                    return false;
                j++;
                cnt++;
                flag[i]=1;
                while(i>0 && flag[i]==1)
                    i--;
            }
            else
                i++;
        }
        if(cnt!=sz)
            return false;
        return true;
    }
};
