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
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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
const int FLAG_SIZE = 1001000;
const int PRIME_SIZE = 80000;


bool flag[FLAG_SIZE];
int prime[PRIME_SIZE];


void sieve()
{
    int ind = 1,i,j;
    double d;

    prime [ ind++ ]  = 2;

    for(i=3;i<FLAG_SIZE;i+=2)
    {
        if(flag[i] == false)
        {
            prime[ind++]=i;

            if(i > FLAG_SIZE/i) ///cause i*i > FLAG_SIZE
                continue;

            for(j=i*i,d=i+i;j<=FLAG_SIZE;j+=d)
                flag[j]=true;
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();
    ll i,n,sum,curr_sum,cnt,x;
    while(1==scanf("%lld",&n))
    {
        ll g = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            g = __gcd(g,x);
        }
        sum = 1;
        n = g;
        for(i=1;prime[i]<=n/prime[i];i++)
        {
            cnt = 0;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];
                curr_sum *= prime[i];
            }
            sum*=(cnt+1);
        }
        if(n>=2)
            sum*=2;

        printf("%lld\n",sum);
    }

    return 0;
}
