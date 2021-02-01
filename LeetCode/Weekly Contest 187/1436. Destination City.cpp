class Solution {
public:
    string destCity(vector<vector<string>>& vec) {
        int n = vec.size(),i;
        map<string,int>mp,mp1;
        for(i=0;i<n;i++)
        {
            mp1[vec[i][0]]++;
            mp[vec[i][1]]++;
        }
        for(i=0;i<n;i++)
        {
            if(mp[vec[i][1]]==1 && mp1[vec[i][1]]==0)
                return vec[i][1];
        }
        return vec[i][1];
    }
};
