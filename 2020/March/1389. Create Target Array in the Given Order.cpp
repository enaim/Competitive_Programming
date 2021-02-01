class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int>vec(n,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>index[i];j--)
                vec[j] = vec[j-1];
            vec[index[i]]=nums[i];
        }
        return vec;
    }
};
