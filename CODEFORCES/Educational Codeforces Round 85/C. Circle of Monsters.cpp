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

ll ar[300010];
ll br[300010];
ll cr[300010];
ll dr[300010];
ll flag[300010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll i,ind,n;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            flag[i]=0LL;
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld",&ar[i],&br[i]);
            cr[i]=ar[i];
            dr[i]=br[i];
        }
        if(n==1LL)
        {
            printf("%lld\n",ar[0]);
            continue;
        }

        ll mn = 1e19;
        ll sum = 0LL;
        for(i=0;i<n;i++)
        {
            sum+=max(0LL,ar[i]);
            if(i<n-1LL)
                ar[i+1]-=br[i];
        }
        mn = sum;
        for(i=1;i<n;i++)
        {
            sum-=cr[i-1];
            sum+=cr[i];
            if(i==1LL)
            {
                cr[0]-=br[n-1];
                sum+=max(0LL,cr[0]);
                sum-=max(ar[i],0LL);
                mn = min(mn,sum);
                continue;
            }
            cr[i-1]-=br[i-2];
            sum+=max(0LL,cr[i-1]);
            sum-=max(ar[i],0LL);
            mn = min(mn,sum);
        }
        cout<<mn<<endl;
    }

    return 0;
}
