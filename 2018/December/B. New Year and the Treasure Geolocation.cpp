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

ll ar1[1010],ar2[1010],br1[1010],br2[1010];

struct node{
    ll x,y,z;
};
node cr[1000010];

bool compare(node a,node b)
{
    if(a.x==b.x && a.y==b.y)
        return a.z<b.z;
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,j,n;

    while(1==scanf("%lld",&n))
    {
        for(i=0;i<n;i++)
            scanf("%lld%lld",&ar1[i],&br1[i]);
        for(i=0;i<n;i++)
            scanf("%lld%lld",&ar2[i],&br2[i]);
        int cnt = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cr[cnt].x=ar1[i]+ar2[j];
                cr[cnt].y=br1[i]+br2[j];
                cr[cnt].z=j;
                cnt++;
            }
        }
        sort(&cr[0],&cr[cnt],compare);
        for(i=0;i<cnt-n;i++)
        {
            if(cr[i].x==cr[i+n-1].x && cr[i].y==cr[i+n-1].y && cr[i].z==0 && cr[i+n-1].z==n-1)
                break;
        }
        printf("%lld %lld\n",cr[i].x,cr[i].y);;
    }

    return 0;
}
