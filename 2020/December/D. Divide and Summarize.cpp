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

set<ll>st;
vector<ll>v;

void go(vector<ll>vec, ll mx, ll mn)
{
    ll mid = (mx+mn)/2LL;
    vector<ll>vec1;
    vector<ll>vec2;
    ll mx1=-OOO,mx2=-OOO,mn1=OOO,mn2=OOO,sum=0LL;
    int i,sz = vec.size();
    for(i=0;i<sz;i++)
    {
        sum+=vec[i];
        if(vec[i]<=mid)
        {
            vec1.pb(vec[i]);
            mx1 = max(mx1,vec[i]);
            mn1 = min(mn1,vec[i]);
        }
        else
        {
            vec2.pb(vec[i]);
            mx2 = max(mx2,vec[i]);
            mn2 = min(mn2,vec[i]);
        }
    }
    st.insert(sum);
    if(vec1.size()!=0 && vec.size()!=vec1.size())
        go(vec1,mx1,mn1);
    if(vec2.size()!=0 && vec.size()!=vec2.size())
        go(vec2,mx2,mn2);
    return;
}


int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,q;
        ll mx=-OOO,mn=OOO;
        ll x;
        v.clear();
        st.clear();

        sf2(n,q);
        for(i=0;i<n;i++)
        {
            sl(x);
            v.pb(x);
            mx = max(mx,x);
            mn = min(mn,x);
        }
        go(v,mx,mn);
        while(q--)
        {
            sf(x);
            if(st.find(x)!=st.end())
                puts("Yes");
            else
                puts("No");
        }
    }

    return 0;
}
