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

const int FLAG_SIZE  = 1000000;
const int PRIME_SIZE = 100000;

bool flag[FLAG_SIZE];
int prime[PRIME_SIZE];

void siEve()
{
    int ind=1,i,j,d;

    prime[ind++]=2;

    for(i=3;i<FLAG_SIZE;i+=2)
    {
        if(flag[i] == false)
        {
            prime[ind++] = i;

            if(i> FLAG_SIZE/i)
                continue;

            for(j=i*i,d=i+i;j<FLAG_SIZE;j+=d)
                flag[j] = true;
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    siEve();

    ll n,cnt,i;
    while(1==scanf("%lld",&n))
    {
        cnt = 0;
        for(i=1;prime[i]<=n/prime[i];i++)
        {
            if(n%prime[i]==0)
                break;
        }
        if(n%2==0)
            cnt = n/2;
        else
        {
            if(n%prime[i]==0)
                n = n-prime[i];
            else
                n = 0;
            cnt = n/2 + 1;
        }
        printf("%lld\n",cnt);
    }

    return 0;
}
