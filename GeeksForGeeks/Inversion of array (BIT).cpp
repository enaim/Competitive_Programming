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
#define SF(a)      scanf("%d",&a)
#define SSF(str)   scanf("%s",str)
#define PF(a)      printf("%d\n",a)
#define SL(a)      scanf("%lld",&a)
#define PL(a)      printf("%lld\n",a)
#define SF2(a,b)   scanf("%d%d",&a,&b)
#define PF2(a,b)   printf("%d %d\n",a,b)
#define SL2(a,b)   scanf("%lld%lld",&a,&b)
#define SF3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define PL2(a,b)   printf("%lld %lld\n",a,b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
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
const int SIZE = 10000010;

int n;
int ar[SIZE];
int BIT[SIZE];

void update(int index,int v)
{
    while(index<=n)
    {
        BIT[index] += v;
        index += index &- index;
    }
}

ll Query(int index)
{
    ll ans = 0;
    while(index>0)
    {
        ans += BIT[index];
        index -= index &- index;
    }
    return ans;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(BIT,0,sizeof BIT);
        int i,m;
        SF(m);
        for(i=1;i<=m;i++)
            SF(ar[i]);
        n = 0;
        for(i=1;i<=m;i++)
            n = max(n,ar[i]);
        ll sum = 0;
        for(i=m;i>=1;i--)
        {
            sum += Query(ar[i]-1);
            update(ar[i],1);
        }
        PL(sum);
    }

    return 0;
}
