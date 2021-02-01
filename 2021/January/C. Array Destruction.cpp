#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

map<int,int>mp;
map<int,int>rmp;
map<int,int>vmp;
vector<int>ans;
vector<int>vec[2010];
int sz[2010];
int ar[2010];
int flag[2010];
set<int>st;
int i,j,cnt,n,a,b,x,mx,sum;

void fun()
{
    for(i=0;i<=2005;i++)
    {
        sz[i]=0;
        flag[i]=0;
        vec[i].clear();
    }
    sf(n);
    n=2*n;
    st.clear();
    mp.clear();
    rmp.clear();
    vmp.clear();
    ans.clear();
    for(i=1;i<=n;i++)
    {
        sf(ar[i]);
        st.insert(ar[i]);
    }
    sort(&ar[1],&ar[n+1],greater<int>());

    int cnt = 1;
    for(auto it:st)
    {
        mp[it]=cnt;
        cnt++;
    }
    for(i=1;i<=n;i++)
    {
        x = mp[ar[i]];
        vec[x].pb(i);
    }
}

void func()
{
    for(j=1;j<=n;j++)
    {
        vmp[ar[j]]=0;
        flag[j]=0;
        sz[j]=0;
    }
    for(j=1;j<=n;j++)
        vmp[ar[j]]++;

    a = mp[ar[1]];
    b = mp[ar[i]];
    vmp[ar[1]]--;
    vmp[ar[i]]--;
    sz[a]++;
    sz[b]++;
    flag[1]=1;
    flag[i]=1;
    j = 2;
    cnt = 2;
    mx = ar[1];
    ans.clear();
    ans.pb(1);
    ans.pb(i);
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        fun();

        for(i=2;i<=n;i++)
        {
            func();
            while(j<n && cnt<n)
            {
                while(j<n && flag[j]!=0)
                    j++;
                if(j==n)
                    break;
                x = mx - ar[j];
                if(vmp.find(x)!=vmp.end() && vmp[x]>0)
                {
                    a = mp[ar[j]];
                    b = mp[x];
                    if(vec[a].size()>sz[a])
                        sz[a]++;
                    else
                        break;
                    if(vec[b].size()>sz[b])
                        sz[b]++;
                    else
                        break;
                    vmp[mx]--;
                    vmp[x]--;
                    ans.pb(vec[a][sz[a]-1]);
                    ans.pb(vec[b][sz[b]-1]);
                    flag[vec[a][sz[a]-1]]=1;
                    flag[vec[b][sz[b]-1]]=1;
                    cnt+=2;
                    mx = max(ar[j],x);
                }
                j++;
            }
            sum = ar[1]+ar[i];
            if(cnt==n)
                break;
        }
        if(i==n+1)
        {
            puts("NO");
            continue;
        }
        puts("YES");
        pf(sum);
        for(i=0;i<n;i+=2)
            pf2(ar[ans[i]],ar[ans[i+1]]);

    }

    return 0;
}
