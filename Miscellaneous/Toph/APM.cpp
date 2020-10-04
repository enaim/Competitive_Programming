#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define OO 2e9+10

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T abs(T x){
    if(x<0)    return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

const int SIZE = 100010;

map<string,int>mp,mp1;
set<string>st,st1;
set<int>st2;
vector<int>vec[SIZE];

int rnk[SIZE],parent[SIZE];

int Find_Set(int x)
{
    if(x!=parent[x])
        parent[x]=Find_Set(parent[x]);
    return parent[x];
}

void Link(int x,int y)
{
    if(rnk[x]>rnk[y])
        parent[y]=x;
    else
    {
        parent[x]=y;
        if(rnk[x]==rnk[y])
            rnk[y]++;
    }
}

void Union(int x,int y)
{
    Link(Find_Set(x),Find_Set(y));
}

void Make_Set(int x)
{
    parent[x]=x;
    rnk[x]=x;
}

string part(string str)
{
    int i;
    string s="";
    for(i=0;i<str.size();i++)
        if(str[i]==':')
            break;
        else
            s = s + str[i];
    return s;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    for(int i=1;i<=1e5;i++)
        Make_Set(i);

    int tks,ks=1;
    int cnt = 50000,cnt1 = 50000,q,sz,i,f,c,x,k;
    string str,str1,s,ss;
    scanf("%d",&tks);
    while(tks--)
    {
        cin>>str>>q;
        if(q==0)
        {
            mp[str] = cnt--;
            ss = part(str);
            if(mp1[ss]==0)
            {
                mp1[ss]=cnt1--;
                vec[cnt+1].push_back(cnt1+1);
            }
            else
                vec[cnt+1].push_back(mp1[ss]);
            st.insert(str);
            printf("Request %d: OK\n",ks++);
            for(auto it:st)
                cout<<it<<endl;
            continue;
        }

        f = 0;
        i = 0;
        st1.clear();
        while(i<q)
        {
            i++;
            cin>>str1;
            if(mp[str1]==0)
                f = 1;
            if(f==0)
                st1.insert(str1);
        }

        if(f)
        {
            printf("Request %d: ERROR\n",ks++);
            continue;
        }

        c = st1.size();
        int sum = 0;
        st2.clear();
        for(auto it : st1)
        {
            x = Find_Set(mp[it]);
            sz = vec[x].size();
            sum+=sz;
            for(k=0;k<sz;k++)
                st2.insert(vec[x][k]);
        }
        if(sum!=st2.size())
            f = 1;
        if(f)
        {
            printf("Request %d: ERROR\n",ks++);
            continue;
        }

        st.insert(str);
        ss = part(str);
        if(mp[str]==0)
            mp[str]=cnt--;
        for(auto it : st1)
        {
            x = Find_Set(mp[it]);
            Union(mp[it],mp[str]);
            x = Find_Set(mp[str]);

            if(mp1[ss]==0)
                mp1[ss]=cnt1--;
            vec[x].push_back(cnt1+1);
        }

        printf("Request %d: OK\n",ks++);
        for(auto it:st)
            cout<<it<<endl;
    }

    return 0;
}
