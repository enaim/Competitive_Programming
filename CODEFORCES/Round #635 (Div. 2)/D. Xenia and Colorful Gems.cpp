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

ll  ar[100010];
ll  br[100010];
ll  cr[100010];
ll aar[100010];
ll bbr[100010];
ll ccr[100010];
ll ans;

void sq(ll a,ll b, ll c)
{
    ans = min(ans,sqr(a-b)+sqr(b-c)+sqr(c-a));
}

void func(int r,int g,int b)
{
    ll x,y,z;
    int i,left,right,mid;

    for(i=0;i<r;i++)
    {
        x = ar[i];

        left = 0;
        right = g-1;
        if(br[left]>x)
            continue;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(br[mid]>x)
                right = mid - 1;
            else
                left = mid+1;
        }
        y = br[left-1];

        left = 0;
        right = b-1;
        if(cr[right]<x)
            continue;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(cr[mid]<x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        z = cr[right+1];
        sq(x,y,z);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int r,g,b,i;
        ans = 1e19;
        scanf("%d%d%d",&r,&g,&b);

        for(i=0;i<r;i++)
            scanf("%lld",&ar[i]);
        for(i=0;i<g;i++)
            scanf("%lld",&br[i]);
        for(i=0;i<b;i++)
            scanf("%lld",&cr[i]);

        sort(&ar[0],&ar[r]);
        sort(&br[0],&br[g]);
        sort(&cr[0],&cr[b]);

        for(i=0;i<r;i++)
            aar[i]=ar[i];
        for(i=0;i<g;i++)
            bbr[i]=br[i];
        for(i=0;i<b;i++)
            ccr[i]=cr[i];

        func(r,g,b);

        for(i=0;i<r;i++)
            cr[i]=aar[i];
        for(i=0;i<g;i++)
            br[i]=bbr[i];
        for(i=0;i<b;i++)
            ar[i]=ccr[i];
        func(b,g,r);

        for(i=0;i<r;i++)
            br[i]=aar[i];
        for(i=0;i<g;i++)
            cr[i]=bbr[i];
        for(i=0;i<b;i++)
            ar[i]=ccr[i];
        func(b,r,g);

        for(i=0;i<r;i++)
            br[i]=aar[i];
        for(i=0;i<g;i++)
            ar[i]=bbr[i];
        for(i=0;i<b;i++)
            cr[i]=ccr[i];

        func(g,r,b);

        for(i=0;i<r;i++)
            cr[i]=aar[i];
        for(i=0;i<g;i++)
            ar[i]=bbr[i];
        for(i=0;i<b;i++)
            br[i]=ccr[i];

        func(g,b,r);

        for(i=0;i<r;i++)
            ar[i]=aar[i];
        for(i=0;i<g;i++)
            cr[i]=bbr[i];
        for(i=0;i<b;i++)
            br[i]=ccr[i];
        func(r,b,g);

        printf("%lld\n",ans);
    }

    return 0;
}
