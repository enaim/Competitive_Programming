#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

ll mod = 1e9+7;

long long BigMod (long long b,long long p,long long M)
{
    long long ans = 1LL;
    while(p)
    {
        if(p & 1)
            ans = (ans * b) % M;
        b = (b * b) % M;
        p = p >> 1;
    }

    return ans;
}

int ar[1010];
int br[1010];
int flag[1100][1100];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int r,w,i,j;
    while(2==scanf("%d%d",&r,&w))
    {
        memset(flag,0,sizeof flag);
        for(i=0;i<r;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<w;i++)
            scanf("%d",&br[i]);

        for(i=0;i<r;i++)
        {
            for(j=0;j<ar[i];j++)
            {
                flag[i][j]+=1;
            }
            flag[i][j]+=2;
        }

        for(i=0;i<w;i++)
        {
            for(j=0;j<br[i];j++)
            {
                flag[j][i]+=1;
            }
            flag[j][i]+=2;
        }

        int f = 0;
        ll cnt = 0LL;
        for(i=0;i<r;i++)
            for(j=0;j<w;j++)
                if(flag[i][j]==0)
                    cnt++;
                else if(flag[i][j]==3)
                    f = 1;

        if(f)
            printf("0\n");
        else
            printf("%lld\n",BigMod(2LL,cnt,mod));
    }

    return 0;
}
