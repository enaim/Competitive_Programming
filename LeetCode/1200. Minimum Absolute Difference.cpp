class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& vec) {
        int n = vec.size();
        int i;
        sort(vec.begin(),vec.end());
        int mn = 1e9;
        for(i=1;i<n;i++)
        {
            if(vec[i]-vec[i-1]<mn)
                mn = vec[i]-vec[i-1];
        }
        vector<vector<int>>ans;
        int cnt = 0;
        for(i=1;i<n;i++)
        {
            if(vec[i]-vec[i-1]==mn)
            {
                vector<int>temp;
                temp.push_back(vec[i-1]);
                temp.push_back(vec[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
