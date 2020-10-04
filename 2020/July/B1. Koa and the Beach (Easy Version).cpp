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

int ar[110];
int br[210];
int dp[110][40010];
int limit,n,t;
int z;

int go(int pos, int k)
{
    if(pos==n+1)
        return k;
    if((ar[pos]+br[k%z])>limit)
        return OO;
    int &re = dp[pos][k];
    if(re != -1)
        return re;
    re = OO;
    for(int i=1;i<=z;i++)
    {
        if(i>1 && (ar[pos]+br[(k+(i-1))%z])>limit && pos!=0)
            return re;
        re = min(re,go(pos+1,k+i));
    }
    return re;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(dp,-1,sizeof dp);
        int cnt = 0,i;
        sf3(n,t,limit);
        z = 2*t;
        for(i=1;i<=n;i++)
            sf(ar[i]);
        for(i=0;i<t;i++)
            br[cnt++]=i;
        for(i=t;i>=1;i--)
            br[cnt++]=i;
        int ans = go(0,0);
        if(ans==OO)
            puts("No");
        else
            puts("Yes");
    }

    return 0;
}
