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

struct box{
    int w;
    int mx_ld;
};

const int SIZE = 1010;
box ar[SIZE];
int dp[SIZE][6010];
int invalid,n;

int BOX(int ind,int rem)
{
    if(ind == n)    return 0;
    int &re =dp[ind][rem];
    if(re != invalid)
        return re;
    re = -OO;

    re = max(re,BOX(ind+1,rem));
    if(rem >= ar[ind].w)
    {
        if(( rem-ar[ind].w ) < ar[ind].mx_ld)
        {
            re = max(re,1+BOX(ind+1,rem-ar[ind].w));
        }
        else
        {
            re = max(re,1+BOX(ind+1,ar[ind].mx_ld));
        }
    }

    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,cnt;
    memset(&invalid,0x1f,sizeof invalid);

    while(1==scanf("%d",&n) && n)
    {
        memset(dp,0x1f,sizeof dp);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&ar[i].w,&ar[i].mx_ld);
        }
        cnt = BOX(0,6005);

        printf("%d\n",cnt);
    }

    return 0;
}
