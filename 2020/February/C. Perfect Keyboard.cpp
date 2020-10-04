#include <bits/stdc++.h>
using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

int flag[30];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tks,ks=1;
    string str,ans;
    cin>>tks;
    while(tks--)
    {
        str.clear();
        ans.clear();
        cin>>str;
        int n = str.size(),i;
        memset(flag,0,sizeof flag);

        for(i=0;i<n;i++)
            flag[str[i]-'a']=1;

        int cnt = 0;
        for(i=0;i<26;i++)
            if(flag[i])
                cnt++;
        if(cnt<=2)
        {
            str.clear();
            for(i=0;i<26;i++)
            {
                if(flag[i]==1)
                {
                    str+=char(i+'a');
                }
            }
            for(i=0;i<26;i++)
            {
                if(flag[i]==0)
                {
                    str+=char(i+'a');
                }
            }
            cout<<"YES"<<endl;
            cout<<str<<endl;
            continue;
        }
        memset(flag,0,sizeof flag);
        int f = 0,start;
        cnt = 0;
        for(i=2;i<n;i++)
        {
            if(str[i]!=str[i-1] && str[i-1]!=str[i-2] && str[i]!=str[i-2] && f==0)
            {
                start = i-2;
                f = 1;
                ans+=str[i-2];          ans+=str[i-1];            ans+=str[i];
                flag[str[i-2]-'a']=1;   flag[str[i-1]-'a']=1;     flag[str[i]-'a']=1;
                cnt = 2;
                continue;
            }
            if(f)
            {
                if(cnt>0 && str[i]==ans[cnt-1])
                {
                    cnt = cnt-1;
                    continue;
                }
                if(cnt<ans.size()-1 && str[i]==ans[cnt+1])
                {
                    cnt = cnt+1;
                    continue;
                }
                if(flag[str[i]-'a']==1 || (cnt!=ans.size()-1 && cnt!=0))
                {
                    f = OO;
                    break;
                }
                if(cnt==0)
                {
                    ans = char(str[i]) + ans;
                    cnt = 0;
                }
                else
                {
                    ans = ans+char(str[i]);
                    cnt = ans.size()-1;
                }
                flag[str[i]-'a']=1;
            }
        }
        if(f==OO)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cnt = 0;
        for(i=0;i<ans.size();i++)
            if(ans[i]==str[start])
            {
                cnt = i;
                break;
            }
        for(i=start-1;i>=0;i--)
        {
            if(cnt>0 && str[i]==ans[cnt-1])
            {
                cnt = cnt-1;
                continue;
            }
            if(cnt<ans.size()-1 && str[i]==ans[cnt+1])
            {
                cnt = cnt+1;
                continue;
            }
            if(flag[str[i]-'a']==1 || (cnt!=ans.size()-1 && cnt!=0))
            {
                f = OO;
                break;
            }
            if(cnt==0)
            {
                ans = char(str[i]) + ans;
                cnt = 0;
            }
            else
            {
                ans = ans+char(str[i]);
                cnt = ans.size()-1;
            }
            flag[str[i]-'a']=1;
        }
        for(i=0;i<26;i++)
        {
            if(flag[i]==0)
            {
                ans+=char(i+'a');
            }
        }
        if(f==OO)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }

    return 0;
}
