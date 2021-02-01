class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int>sums;
        vector<int>vec = mat[0];

        for(int i=1;i<mat.size();i++)
        {
            sums.clear();
            sums.resize(0);
            for(int j=0;j<vec.size();j++)
            {
                for(int k=0;k<mat[i].size();k++)
                {
                    sums.push_back(mat[i][k]+vec[j]);
                }
            }
            sort(sums.begin(),sums.end());
            sums.resize(min(k,(int)sums.size()));
            swap(vec,sums);
        }
        return vec.back();
    }
};
