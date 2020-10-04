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

const int Flag_Size = 1000010;
const int Prime_Size = 80010;

bool flag[Flag_Size];
ll prime[Prime_Size];
int ind;

void Sieve()
{
    int i,j,d;
    ind = 1;
    prime[ind++]=2;

    for(i=3;i<Flag_Size;i+=2)
    {
        if(flag[i]==false)
        {
            prime[ind++]=i;
            if(i>Flag_Size/i)
                continue;
            for(j=i*i,d = i+i;j<Flag_Size;j+=d)
                flag[j]=true;
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Sieve();

    ll i,cnt,n,ans;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        ll temp = sqrt(n);
        ll m = n;
        ans = 1;
        for(i=1;prime[i]<=n/prime[i];i++)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];
            }
            ans*=(cnt+1);
        }
        if(n!=1)
            ans*=2;

        printf("Case %d: %lld\n",ks++,ans-1);
    }
    return 0;
}
