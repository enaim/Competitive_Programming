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

ll ar[1010][1010];
ll ans[1010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,j,n,g;
    while(1==scanf("%lld",&n))
    {
        vector<ll>vec;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%lld",&ar[i][j]);
        g = 0LL;
        for(i=1;i<n-1;i++)
            g = __gcd(ar[0][i],g);
        ll s = sqrt(g);
        vec.pb(g);
        vec.pb(1);
        for(i=2;i<=s;i++)
        {
            if(g%i==0)
            {
                ll x = g/i;
                vec.pb(i);
                if(i!=x)
                    vec.pb(x);
            }
        }
        ll sz = vec.size();
        ll k = 0;
        while(true)
        {
            ans[0]=vec[k];
            k++;
            for(i=1;i<n;i++)
                ans[i]=ar[0][i]/ans[0];
            int f = 1;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i==j)
                        continue;
                    if(ans[i]*ans[j]!=ar[i][j])
                    {
                        f = 0;
                        break;
                    }
                }
            }
            if(f)
                break;
        }

        for(i=0;i<n;i++)
            printf("%lld ",ans[i]);
    }

    return 0;
}
