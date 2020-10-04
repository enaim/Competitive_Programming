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

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

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

ll dp[32][32][910];

ll go(ll n,ll m,ll k)
{
    if(k==1LL)
        return n*m;
    if(k==0LL)
        return 1LL;
    if(m==1LL)
        return 0;
    if(k>n || k>m)
        return 0;
    ll &re = dp[n][m][k];
    if(re!=-1)
        return re;
    return re = n*go(n-1,m-1,k-1)+go(n,m-1,k);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,kk;
    for(i=0;i<31;i++)
        for(j=0;j<31;j++)
            for(kk=0;kk<901;kk++)
                dp[i][j][kk]=-1;

    ll n,k;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&k);
        ll ans = go(n,n,k);
        printf("Case %d: %lld\n",ks++,ans);
    }

    return 0;
}
