int pos[1010];

class Solution {
public:
    vector<int> processQueries(vector<int>& vec, int m) {
        int i;
        vector<int>ans;
        vector<int>ano;
        memset(pos,-1,sizeof pos);
        for(i=1;i<=m;i++)
        {
            pos[i]=i-1;
            ano.push_back(i);
        }
        int j;
        for(i=0;i<vec.size();i++)
        {
            ans.push_back(pos[vec[i]]);
            for(j=pos[vec[i]]-1;j>=0;j--)
            {
                ano[j+1]=ano[j];
                pos[ano[j+1]]++;
            }
            pos[vec[i]]=0;
            ano[0]=vec[i];
        }
        return ans;
    }
};
