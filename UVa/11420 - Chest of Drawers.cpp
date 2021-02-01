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

long long invalid,N;
long long dp[70][70][2];

long long Go(long long n,long long k,long long last_lock)
{
    if(n == 0 && k==0)    return 1;
    if(n==0)              return 0;
    if(n < k)     return 0;

    long long &re = dp[n][k][last_lock];
	
    if(re > -1)   return re;
    re = 0;

    if(last_lock)
        re = Go(n-1,k,0) + Go(n-1,k-1,1);
    else
        re = Go(n-1,k,0) + Go(n-1,k,1);

    return re;
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long cnt,i,n,k;
    memset(dp,-1,sizeof dp);

    while(2==scanf("%lld%lld",&n,&k) && n>-1)
    {
        N=n;
        cnt = Go(n,k,1);
        printf("%lld\n",cnt);
    }

    return 0;
}
