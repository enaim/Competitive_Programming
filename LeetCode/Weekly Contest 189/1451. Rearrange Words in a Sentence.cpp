class Solution {
public:
    string arrangeWords(string text) {

        map<int,vector<string>>mp;
        text[0] = tolower(text[0]);
        text+=" ";

        int i, cnt=0;
        string s="";
        int l = text.size();

        for(i=0;i<l;i++)
        {
            if(text[i]==' ')
            {
                int t = s.size();
                mp[t].push_back(s);
                s = "";
                cnt++;
                continue;
            }
            s = s + text[i];
        }

        text = "";
        for(auto m:mp)
        {
            for(auto it : m.second)
                text += it + " ";
        }
        text.pop_back();
        text[0]=toupper(text[0]);
        return text;
    }
};
