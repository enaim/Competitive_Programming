class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>cnt1,cnt2,vec;
        set<int>st1,st2;
        int i,cnt = 1;

        if(word1.size()!=word2.size())
            return false;

        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());

        for(i=0;i<word1.size();i++)
            st1.insert(word1[i]);
        for(i=0;i<word2.size();i++)
            st2.insert(word2[i]);

        if(st1.size()!=st2.size())
            return false;
        for(auto it:st1)
            vec.push_back(it);

        int cur=0;
        for(auto it:st2)
        {
            if(it!=vec[cur])
                return false;
            cur++;
        }

        for(i=1;i<word1.size();i++)
        {
            if(word1[i]==word1[i-1])
                cnt++;
            else
                cnt1.push_back(cnt),cnt = 1;
        }
        cnt1.push_back(cnt);

        cnt = 1;
        for(i=1;i<word2.size();i++)
        {
            if(word2[i]==word2[i-1])
                cnt++;
            else
                cnt2.push_back(cnt),cnt = 1;
        }
        cnt2.push_back(cnt);

        sort(cnt1.begin(),cnt1.end());
        sort(cnt2.begin(),cnt2.end());
        if(cnt1.size() != cnt2.size())
            return false;

        for(i=0;i<cnt1.size();i++)
            if(cnt1[i]!=cnt2[i])
                return false;
        return true;
    }
};
