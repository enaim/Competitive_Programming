#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <bitset>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

ll equation(ll n)
{
    ll a = n;
    ll b = n+1;
    return (a*b)/2LL;
}

ll ans;
int ar[5];
queue<int>Q;
vector<int>vv;
int sz1[100010];
int sz2[100010];
int par[100010];
int deg[100010];
int vis[100010];
int n,temp1,temp2;
vector<int>vec[100010];
new_data_set pst,st[100010];

void path()
{
    vv.clear();
    int cnt = 0;
    int i,u,v;
    ll a,b,large,small;
    u = temp1;
    while(cnt<n)
    {
        vis[u]=1;
        vv.pb(u);
        cnt++;
        if(cnt==n)
            break;
        int sz = vec[u].size();
        for(i=0;i<sz;i++)
        {
            v = vec[u][i];
            if(vis[v]==0)
            {
                u = v;
                break;
            }
        }
    }
    int s = 0;
    for(i=0;i<n;i++)
    {
        int x = pst.order_of_key(vv[i]);
        a = x;
        b = s - a;
        small = vv[i]-1;
        small -= a;
        large = n - vv[i];
        large -= b;

        if(ar[2]==2)
        {
            ans+=(a*large);
            ans+=(b*small);
        }
        else if(ar[2]==1)
            ans+=(b*large);
        else
            ans+=(a*small);
        pst.insert(vv[i]);
        s++;
    }
}

void star()
{
    ll small = temp2-1;
    ll large = n-temp2;
    if((ar[1]<ar[2] && ar[2]<ar[3]) || (ar[1]>ar[2] && ar[2]>ar[3]))
        ans += (small*large);
    else if(ar[2]<ar[1] && ar[2]<ar[3])
        ans += equation(max(0LL,large-1LL));
    else
        ans += equation(max(0LL,small-1LL));
}


void call(int u,int w)
{
    int szz = vec[w].size();
    int cnt = 0;
    for(int i=0;i<szz;i++)
    {
        int z = par[vec[w][i]];
        int zz = par[w];
        if(deg[vec[w][i]]==0)
        {
            if(vis[zz]>=vis[z])
            {
                for(auto it: st[z])
                {
                    st[zz].insert(it),vis[zz]++;
                }
            }
            else
            {
                for(auto it: st[zz])
                {
                    st[z].insert(it),vis[z]++;
                }
                par[w] = z;
            }
        }
    }
    st[par[w]].insert(w);
    vis[par[w]]++;

    ll a,b,small,large;
    deg[u]--;
    deg[w] = 0;

    int x = st[par[w]].order_of_key(u);
//    int x = cnt;
    a = x;
    b = vis[par[w]] - a;
    small = sz1[u]-a;
    small = max(0LL,small);
    large = sz2[u] - b;
    large = max(0LL,large);

    sz1[u] -= a;
    sz2[u] -= b;

    if(deg[u]==1)
        Q.push(u);

    if(ar[2]==2)
    {
        ans+=(a*large);
        ans+=(b*small);
    }
    else if(ar[2]==1)
        ans+=(b*large);
    else
        ans+=(a*small);
}

void func()
{
    int i,sz,u,v;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        sz = vec[u].size();
        for(i=0;i<sz;i++)
        {
            v = vec[u][i];
            if(deg[v])
            {
                call(v,u);
                break;
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,u,v;
    ll a,b,small,large;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        for(i=1;i<=3;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            deg[u]++,deg[v]++;
            vec[u].pb(v);
            vec[v].pb(u);
        }

        int cnt1,cnt2;
        cnt1 = cnt2 = 0;
        for(i=1;i<=n;i++)
        {
            par[i]=i;
            if(deg[i]==1)
                cnt1++,temp1=i,Q.push(i);
            else if(deg[i]==2)
                cnt2++;
            else
                temp2 = i;
            sz1[i] = i-1;
            sz2[i] = n-i;
        }
        ans = 0LL;
        int f = 0;
        pst.clear();
        //path
        if(cnt1==2 && cnt2==n-2)
            path(),f=1;
        //star
        if(cnt1==n-1 && f==0)
            star(),f=1;

        if(f==0)
            func();

        printf("%lld\n",ans);
        for(i=1;i<=n;i++)
        {
            sz1[i]=0;
            sz2[i]=0;
            deg[i]=0;
            vis[i]=0;
            st[i].clear();
            vec[i].clear();
        }
        while(!Q.empty())
            Q.pop();
    }

    return 0;
}
