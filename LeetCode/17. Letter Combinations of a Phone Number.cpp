map<int,string>mp;
void func()
{
    mp[2]="abc";
    mp[3]="def";
    mp[4]="ghi";
    mp[5]="jkl";
    mp[6]="mno";
    mp[7]="pqrs";
    mp[8]="tuv";
    mp[9]="wxyz";
}

int k;
string digit;
set<string>st;

void go(string str,int pos)
{
    if(k==pos)
    {
        if(str.size()>0)
            st.insert(str);
        return;
    }
    int dig = digit[pos]-'0';
    int sz = mp[dig].size();
    string temp = str;
    for(int i=0;i<sz;i++)
    {
        str=temp+mp[dig][i];
        go(str,pos+1);
    }
}

class Solution {
public:
    vector<string> letterCombinations(string str) {
        st.clear();
        func();
        int n = str.size();
        digit = str;
        k = n;
        string s="";
        go(s,0);
        vector<string>vec;
        for(auto it:st)
            vec.push_back(it);
        return vec;
    }
};
