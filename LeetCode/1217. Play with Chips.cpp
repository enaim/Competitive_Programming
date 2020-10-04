class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int n = chips.size();
        int i,cnt1=0,cnt2=0;
        for(i=0;i<n;i++)
            if(chips[i]%2==0)
                cnt2++;
            else
                cnt1++;
        return min(cnt1,cnt2);
    }
};
