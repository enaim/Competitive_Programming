class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& ar) {
        vector<int>vec[100010],ans;
        int n = ar.size();
        int i,j;
        for(i=0;i<n;i++)
            for(j=0;j<ar[i].size();j++)
                vec[i+j].push_back(ar[i][j]);
        for(i=0;i<1e5;i++)
        {
            reverse(vec[i].begin(),vec[i].end());
            for(j=0;j<vec[i].size();j++)
                ans.push_back(vec[i][j]);
        }
        return ans;
    }
};
