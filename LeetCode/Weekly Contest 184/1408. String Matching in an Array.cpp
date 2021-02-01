class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>vec;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(words[j].find(words[i])!=-1 && words[i]!=words[j])
                {
                    vec.push_back(words[i]);
                    break;
                }
            }
        }
        return vec;
    }
};
