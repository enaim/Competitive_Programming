int flag[100010];
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        memset(flag,0,sizeof flag);
        int n= s.size(),i;
        stack<int>first;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
                first.push(i);
            if(s[i]==')')
            {
                if(!first.empty())
                    first.pop();
                else
                    flag[i]=1;
            }
        }
        while(!first.empty())
        {
            flag[first.top()]=1;
            first.pop();
        }
        string temp="";
        for(i=0;i<n;i++)
        {
            if(flag[i])
                continue;
            temp+=s[i];
        }
        return temp;
    }
};
