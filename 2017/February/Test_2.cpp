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

const int SIZE = 100;

int ar[SIZE];
int dp[SIZE][2];
int N;
int invalid;

int go(int pos,int jump)
{
    if(pos<1)  return -OO;
    if(pos==1)     return ar[pos];

    int &re = dp[pos][jump];
    if(re!=invalid)   return re;
    re = -OO;

    re = max(re,ar[pos]+go(pos-2,0));
    re = max(re,ar[pos]+go(pos-4,0));
    re = max(re,ar[pos]+go(pos-6,0));
    if(!jump)
        re = max(re,ar[pos]+go(pos-1,1));

    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int result;

    memset(&invalid,0x1f,sizeof invalid);

    while(1==scanf("%d",&N))
    {
        memset(dp,0x1f,sizeof dp);
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&ar[i]);
        }

        result = go(N,0);
        printf("Result -> %d\n",result);
    }

    return 0;
}
