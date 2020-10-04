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
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

int n;
int dp[210][110];
int ar[210][110];

int go(int l,int k)
{
    if(l==2*n-1)
        return ar[l][k];

    int &re = dp[l][k];

    if(re!=0)
        return re;

    re = 0;
    if(l<n)
    {
        re = max(re,ar[l][k]+go(l+1,k));
        re = max(re,ar[l][k]+go(l+1,k+1));
    }
    else
    {
        if(k != 1)
            re = max(re,ar[l][k]+go(l+1,k-1));
        if(k != 2*n-l)
            re = max(re,ar[l][k]+go(l+1,k));
    }
    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,ans;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(dp,0,sizeof dp);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
                scanf("%d",&ar[i][j]);
        }
        for(i=1;i<n;i++)
        {
            for(j=1;j<=n-i;j++)
                scanf("%d",&ar[n+i][j]);
        }
        ans = go(1,1);
        printf("Case %d: %d\n",ks++,ans);
    }

    return 0;
}
