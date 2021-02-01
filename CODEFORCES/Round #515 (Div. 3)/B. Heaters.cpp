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

int ar[1010],sz[1010],pos[1010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int cnt,cnt1,i,j,n,r,flag;

    while(2==scanf("%d%d",&n,&r))
    {
        cnt = 0;
        cnt1 = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);
            if(ar[i]==1)
                pos[++cnt]=i;
        }
        for(i=1;i<=cnt;i++)
        {
            for(j=max(1,pos[i]-r+1);j<=min(n,pos[i]+r-1);j++)
                sz[j]++;
        }
        for(i=1;i<=cnt;i++)
        {
            flag = 1;
            for(j=max(1,pos[i]-r+1);j<=min(n,pos[i]+r-1);j++)
            {
                if(sz[j]<=1)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                cnt1++;
                for(j=max(1,pos[i]-r+1);j<=min(n,pos[i]+r-1);j++)
                    sz[j]--;
            }
        }
        flag = 1;
        for(i=1;i<=n;i++)
            if(sz[i]==0)
            {
                flag=0;
                break;
            }
        if(flag==0)
            printf("-1\n");
        else
            printf("%d\n",cnt-cnt1);
    }

    return 0;
}
