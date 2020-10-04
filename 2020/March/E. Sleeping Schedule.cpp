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
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

int dp[4010][2010];
int ar[2010];
int n,h,l,r;

int go(int last,int pos)
{
    if(pos==n)
        return 0;

    int &re = dp[last][pos];
    if(re!=-1)
        return re;

    re = 0;
    int x = (last+ar[pos])%h;
    if(l<=x && x<=r)
        re = max(re,go(x,pos+1)+1);
    else
        re = max(re,go(x,pos+1));

    x = (last+ar[pos]-1)%h;

    if(l<=x && x<=r)
        re = max(re,go(x,pos+1)+1);
    else
        re = max(re,go(x,pos+1));

    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(4==scanf("%d%d%d%d",&n,&h,&l,&r))
    {
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++)
            scanf("%d",&ar[i]);
        int ans = go(0,0);
        printf("%d\n",ans);
    }

    return 0;
}
