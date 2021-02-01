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

int n,kk;
int ar[101];
int dp[101][10001];

int go(int pos,int k)
{
    if(k<=0)
        return kk + abs(k);
    if(pos==n)
        return OO;

    int &re = dp[pos][k];
    if(re != -1)
        return re;

    re = OO;
    re = min(re,go(pos+1,k-ar[pos]));
    re = min(re,go(pos+1,k));
    return re;
}

int go1(int pos,int k)
{
    if(k==0)
        return 0;
    if(pos==n || k<0)
        return OO;

    int &re = dp[pos][k];
    if(re != -1)
        return re;

    re = OO;
    re = min(re,go1(pos+1,k-ar[pos])+1);
    re = min(re,go1(pos+1,k));
    return re;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,cnt,ans;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&kk);
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        memset(dp,-1,sizeof dp);
        ans = go(0,kk);
        memset(dp,-1,sizeof dp);
        cnt = go1(0,ans);
        printf("%d %d\n",ans,cnt);
    }

    return 0;
}
