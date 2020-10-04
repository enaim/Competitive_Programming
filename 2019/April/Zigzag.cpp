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

int dp[55][55][2];
int n;
int ar[60];

int go(int pos,int last,int k)
{
    if(pos==n)
        return 0;
    int &re = dp[pos][last][k];
    if(re!=-1)
        return re;

    re = 0;

    re = go(pos+1,last,k);
    if(k==1 && last>ar[pos])
        re = max(re,go(pos+1,ar[pos],0)+1);
    if(k==0 && last<ar[pos])
        re = max(re,go(pos+1,ar[pos],1)+1);

    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,ans;
    while(1==scanf("%d",&n))
    {
        memset(dp,-1,sizeof dp);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        int ans = go(0,52,1);
        ans = max(ans,go(0,0,0));
        printf("%d\n",ans);
    }

    return 0;
}
