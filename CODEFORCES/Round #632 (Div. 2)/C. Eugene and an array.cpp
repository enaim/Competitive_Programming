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

map<ll,ll>mp;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,n,ans,sum,x,s;
    while(1==scanf("%lld",&n))
    {
        mp[0LL]=0LL;
        sum = ans = 0;
        s = -1LL;
        for(i=1LL;i<=n;i++)
        {
            scanf("%lld",&x);
            sum+=x;
            if(mp.find(sum)!= mp.end())
                s = max(s,mp[sum]);
            ans+=i-s-1;
            mp[sum]=i;
        }
        cout<<ans<<endl;
    }

    return 0;
}
