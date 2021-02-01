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

struct node{
   ll ind,val;
};
node ar[200010];
bool compare(node a, node b)
{
    return a.val<b.val;
}
vector<ll>vec;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll i,n,w,sum,h;
        sl2(n,w);
        for(i=0;i<n;i++)
            ar[i].ind = i;
        for(i=0;i<n;i++)
            sl(ar[i].val);
        sort(&ar[0],&ar[n],compare);
        h = (w+1LL)/2LL;
        sum = 0;
        vec.clear();
        for(i=n-1;i>=0;i--)
        {
            if(ar[i].val>w)
                continue;
            sum+=ar[i].val;
            vec.pb(ar[i].ind);
            if(sum>=h)
                break;
        }
        if(sum>=h)
        {
            ll sz = vec.size();
            pl(sz);
            for(i=0;i<sz;i++)
                printf("%lld ",vec[i]+1LL);
            nn;
        }
        else
            puts("-1");
    }

    return 0;
}
