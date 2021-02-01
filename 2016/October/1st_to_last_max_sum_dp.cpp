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

const int SIZE = 100;

int ar[SIZE];
int dp[SIZE];
int N;
int invalid;

int go(int pos)
{
    if(pos==N)  return -OO;
    if(pos==(N-1))     return ar[pos];

    int &re = dp[pos];
    if(re!=invalid)   return re;
    re = -OO;

    re = max(re,ar[pos]+go(pos+1));
    re = max(re,ar[pos]+go(pos+2));

    return re;
}



int main()
{
//    freopen("1.in","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,result;
    memset(&invalid,0x1f,sizeof invalid);

    while(1==scanf("%d",&N))
    {
        memset(dp,0x1f,sizeof dp);

        for(i=0;i<N;i++)
        {
            scanf("%d",&ar[i]);
        }
        result = go(0);
        printf("Result is - > %d\n",result);
    }

    return 0;
}

