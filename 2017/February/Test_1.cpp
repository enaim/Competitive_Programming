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

int ar[100];
int dp[100];
int invalid;
int n;

int go(int pos)
{
    if( pos ==((1<<n)-1))   return 0;

    int &re=dp[pos];
    if(re!=invalid)   return re;
    re = OO;

    for(int i=0;i<n;i++)
    {
        if(pos & (1<<i))
        {
            if(pos | ar[i] > pos)
                re = min(re,1 + go(pos | ar[i]));
        }

    }
    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int result,e,l,i,m,a,j,x,val,lock;
    memset(&invalid,0x1f,sizeof invalid);

    while(3==scanf("%d%d%d",&n,&e,&l))
    {
        memset(dp,0x1f,sizeof dp);

        for(i=0;i<e;i++)
        {
            scanf("%d%d",&x,&m);
            val = 0;
            for(j=0;j<m;j++)
            {
                scanf("%d",&a);
                val|= (1<<a);
            }
            ar[x]=val;
        }
        lock = 0;
        for(i=0;i<l;i++)
        {
            scanf("%d",&a);
            lock |= (1<<a);
        }

        result = go(lock);
        printf("result - > %d\n",result);
    }

    return 0;
}
