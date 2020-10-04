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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

ll i,j,x,day,rem,b,z,y,n,p,h,a,cnt,t;

priority_queue<ll>pq;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&n,&a,&b,&x,&y,&z);

        for(i=0;i<n;i++)
        {
            scanf("%lld",&t);
            pq.push(t);
        }

        p = z-a;
        h = z-b;
        if(h%y==0LL)
            day = h/y;
        else
            day = (h/y)+1LL;

        rem = p - ((day-1LL)*x);
        ll ans = 0LL;

        while(!pq.empty() && rem>0LL)
        {
            x = pq.top();
            pq.pop();
            pq.push(x/2LL);
            rem-=x;
            ans++;
        }
        while(!pq.empty())
            pq.pop();

        if(rem<=0LL)
            printf("%lld\n",ans);
        else
            printf("RIP\n");
    }

    return 0;
}
