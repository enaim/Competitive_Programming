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

const int FLAG_SIZE = 10001000;
const int PRIME_SIZE = 700000;

bool flag[FLAG_SIZE];
int prime[PRIME_SIZE];

void sieve()
{
    int i,j,ind = 1,d;
    prime[ind++]=2;

    for(i=3;i<FLAG_SIZE;i+=2)
    {
        if(flag[i] == false)
        {
            prime[ind++]=i;

            if(i > FLAG_SIZE/i)
                continue;

            for(j=i*i,d=i+i;j<=FLAG_SIZE;j+=d)
                flag[j]=true;
        }
    }
}

vector<int>vec;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sieve();
    ll n,ans;
    int tks,ks=1,i,cnt;
    scanf("%d",&tks);
    while(tks--)
    {
        vec.clear();
        scanf("%lld",&n);
        for(i=1;prime[i]<=n/prime[i];i++)
        {
            cnt = 0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            vec.pb(2*cnt + 1);
        }
        ans = 1;
        if(n!=1)
            vec.pb(3);
        for(auto it:vec)
            ans*=it;
        ans++;
        printf("Case %d: %lld\n",ks++,ans/2LL);
    }

    return 0;
}
