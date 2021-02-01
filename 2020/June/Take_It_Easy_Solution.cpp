#include<bits/stdc++.h>
using namespace std;

string getResult(string s, string t)
{
    string format1="",format2="";
    vector<int>vec1,vec2;

    int cnt,i;
    for(i=0; i<s.size(); i++)
    {
        if(i==0)
        {
            cnt = 1;
            format1+=s[i];
            continue;
        }
        else if(s[i-1]!=s[i])
        {
            format1+=s[i];
            vec1.push_back(cnt);
            cnt = 1;
        }
        else
            cnt++;
    }
    vec1.push_back(cnt);

    for(i=0; i<t.size(); i++)
    {
        if(i==0)
        {
            cnt = 1;
            format2+=t[i];
            continue;
        }
        else if(t[i-1]!=t[i])
        {
            format2+=t[i];
            vec2.push_back(cnt);
            cnt = 1;
        }
        else
            cnt++;
    }
    vec2.push_back(cnt);

    if(format1!=format2 || vec1.size()!=vec2.size())
        return "NO";

    if(format1.size()==1 && t!=s)
        return "NO";

    for(i=0; i<vec2.size(); i++)
    {
        if(vec1[i]>=vec2[i] && (vec1[i]-vec2[i])%2==0)
            continue;
        return "NO";
    }
    return "YES";
}

int main()
{
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        string s,t;
        cin>>s;
        cin>>t;
        printf("Case #%d: ",ks++);
        cout<<getResult(s,t)<<endl;
    }

    return 0;
}
