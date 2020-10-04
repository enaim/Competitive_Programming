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


struct node{
    ll x,y;
};

node ar[100010];

bool compare(node a,node b)
{
    if(a.x==b.x)
        return a.y>b.y;
    else
        return a.x<b.x;
}

ll ans[100100];
vector<ll>vec[100010];
ll n,m,i,mx,mxj,j,sz;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    while(2==scanf("%lld%lld",&n,&m))
    {
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld",&ar[i].x,&ar[i].y);
        }
        sort(&ar[0],&ar[n],compare);

        for(i=0;i<n;i++)
            vec[ar[i].x].pb(ar[i].y);
        mxj = 0;
        for(i=1;i<=m;i++)
        {
            sz = vec[i].size();
            ll sum = 0;
            for(j=0;j<sz;j++)
            {
                sum+=vec[i][j];
                ans[j+1] = max(ans[j+1],ans[j+1]+sum);
                mxj = (mxj,j+1);
            }
        }
        mx = -1e18;
        for(i=1;i<=mxj+5;i++)
        {
            mx = max(ans[i],mx);
        }
        printf("%lld\n",max(0LL,mx));

    }

    return 0;
}
