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

ll ans,g,x,i,ind,n,m;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%lld%lld",&n,&m))
    {
        g = 0;
        scanf("%lld",&x);
        ans=x;
        ll last = x;
        for(i=1;i<n;i++)
        {
            scanf("%lld",&x);
            g = __gcd(g,x-last);
            last = x;
        }
        ll f = 0LL;
        for(i=0;i<m;i++)
        {
            scanf("%lld",&x);
            if(g%x==0)
                f=1LL,ind = i+1;
        }
        if(f)
            printf("YES\n%lld %lld\n",ans,ind);
        else
            printf("NO\n");
    }

    return 0;
}
