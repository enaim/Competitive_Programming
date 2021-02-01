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

ll ans[1000010];
ll pre[1000010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ans[3]=0;
    pre[3]=0;
    ll cnt = 0,i;
    for(i=4;i<=1e6;i++)
    {
        if(i%2LL==0LL)
        {
            cnt++;
            pre[i]=pre[i-1]+cnt;
            ans[i] =ans[i-1]+pre[i];
        }
        else
        {
            pre[i]=pre[i-1]+cnt;
            ans[i] =ans[i-1]+pre[i];
        }
    }

    ll n;
    while(1==scanf("%lld",&n) && n>=3)
        printf("%lld\n",ans[n]);

    return 0;
}
