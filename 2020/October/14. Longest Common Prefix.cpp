class Solution
{
public:
    string longestCommonPrefix(vector<string>& vec)
    {
        if(vec.size()==0)
            return "";
        string ans = vec[0];
        int n = vec.size();
        int i,j;
        for(i=1; i<n; i++)
        {
            string temp = "";
            for(j=0; j<ans.size() && j<vec[i].size(); j++)
            {
                if(ans[j] == vec[i][j])
                    temp += ans[j];
                else
                    break;
            }
            ans = temp;
        }
        return ans;
    }
};
