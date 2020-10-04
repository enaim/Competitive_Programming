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

ll fact[250010];
ll dif[250010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll mod,n,sum,i;

    while(2==scanf("%lld%lld",&n,&mod))
    {
        fact[0]=1LL;
        for(i=1;i<=n;i++)
            fact[i] = ((fact[i-1]%mod)*(i%mod))%mod;

        ll sum = (fact[n]*n)%mod;
        for(i=1;i<n;i++)
            dif[i] = (((fact[i+1]*fact[n-(i+1)])%mod)*(n-i))%mod;   ///in range , out of range and all possible position

        for(i=1;i<n;i++)
            sum = (sum + ((dif[i]*(n-i))%mod))%mod;

        printf("%lld\n",sum);
    }

    return 0;
}
