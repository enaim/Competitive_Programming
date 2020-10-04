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

int ar[]={1,5,10,25,50};
long long dp[30010][10];

long long COIN(int pos,int n)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;

    long long &re = dp[n][pos];
    
    if(re != -1)
        return re;

    re = 0;
    for(int i=pos;i<5;i++)
    {
        re += COIN(i,n-ar[i]);
    }

    return re;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    memset(dp,-1,sizeof dp);
    int n;
    long long result;

    while(1==scanf("%d",&n))
    {
        result = COIN(0,n);

        if(result == 1)
            printf("There is only 1 way to produce %d cents change.\n",n);
        else
            printf("There are %lld ways to produce %d cents change.\n",result,n);
    }

    return 0;
}
