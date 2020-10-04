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

int invalid;
int dp[100][100];

int Go(int n,int k)
{
    if(k == 0)    return 1;
    if(n < k)     return 0;

    int &re = dp[n][k];

    if(re != invalid)   return re;

    re = Go(n-1,k)+Go(n-1,k-1);

    return re;
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int cnt,i,n,k;

    memset(&invalid,0x1f,sizeof invalid);
    while(2==scanf("%d%d",&n,&k))
    {
        memset(dp,0x1f,sizeof dp);
        cnt = Go(n,k);
        printf("Total Way -> %d\n",cnt);
    }

    return 0;
}
