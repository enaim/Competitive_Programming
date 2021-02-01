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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

int n,dp[25][5];
int ar[25][5];

int go(int pos,int k)
{
    int j;

    if(pos==n)
        return 0;

    int &re = dp[pos][k];

    if(re!=-1)
        return re;

    re = OO;

    for(j=0;j<3;j++)
        if(k!=j)
            re = min(re,ar[pos][j]+go(pos+1,j));
    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(dp,-1,sizeof dp);

        scanf("%d",&n);

        for(i=0;i<n;i++)
            for(j=0;j<3;j++)
                scanf("%d",&ar[i][j]);

        int ans = OO;

        for(j=0;j<3;j++)
            ans = min(ans,ar[0][j]+go(1,j));
        printf("Case %d: %d\n",ks++,ans);
    }

    return 0;
}
