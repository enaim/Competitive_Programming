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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

int n;
long long dp[22][22];

long long go(int i,int j)
{
    if(i==1 && j==1)
        return 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    long long  sum=0;

    if(i-1>=1)
        sum+=go(i-1,j);
    if(j-1>=1)
        sum+=go(i,j-1);

    dp[i][j] = sum;

    return dp[i][j];
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    memset(dp,-1,sizeof dp);
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        long long sum = go(n,n);
        printf("%lld\n",sum);
    }

    return 0;
}
