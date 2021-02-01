vector<int> intersection(vector<int>&v1, vector<int>&v2)
{
    vector<int>v3;
    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));
    return v3;
}

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& fc) {
        map<string,vector<int>>mp;
        int i,j,n = fc.size();
        for(i=0;i<n;i++)
            for(auto str:fc[i])
                mp[str].push_back(i);
        vector<int>ans;
        for(i=0;i<n;i++)
        {
            vector<int>v3 = mp[fc[i][0]];
            for(j=1;j<fc[i].size();j++)
                v3 = intersection(mp[fc[i][j]],v3);
            if(v3.size()==1 && v3[0]==i)
                ans.push_back(i);
        }
        return ans;
    }
};
