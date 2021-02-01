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
const int M = 10056;

int res[1010];
int dp[1010][1010];

void nCr(int n,int r)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=r;j++)
        {
            if(j==0 || j==i)
                dp[i][j]=1;
            else
                dp[i][j]=((dp[i-1][j-1]%M)+(dp[i-1][j]%M))%M;
        }
    }
}

void pre_calculate()
{
    int i,j;
    res[0]=1;
    res[1]=1;
    res[2]=3;
    for(i=3;i<=1000;i++)
        for(j=i-1;j>=0;j--)
            res[i] = (res[i]%M)+(((res[j]%M)*(dp[i][i-j]%M))%M);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    nCr(1000,1000);
    pre_calculate();

    int tks,ks=1,n;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",ks++,res[n]);
    }

    return 0;
}
