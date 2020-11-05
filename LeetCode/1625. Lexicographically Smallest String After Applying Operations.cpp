string ans = "";
set<string>st;

string Add(string str, int a)
{
    int i, n = str.size();
    for(i=1; i<n; i+=2)
    {
        str[i] = ((str[i]-'0' + a)%10) + '0';
    }
    return str;
}

string Rotate(string str, int b)
{
    reverse(str.begin(),str.end());
    reverse(str.begin(),str.begin()+b);
    reverse(str.begin()+b,str.end());
    return str;
}

void visit(string str)
{
    ans = min(str,ans);
    st.insert(str);
}

bool isVisited(string str)
{
    return (st.find(str) != st.end());
}

void go(string str, int a, int b)
{
    if(isVisited(str))
    {
        return;
    }
    visit(str);
    go(Add(str,a), a, b);
    go(Rotate(str,b), a, b);
    return;
}


class Solution
{
public:
    string findLexSmallestString(string str, int a, int b)
    {
        st.clear();
        ans = str;
        go(str, a, b);
        return ans;
    }
};
