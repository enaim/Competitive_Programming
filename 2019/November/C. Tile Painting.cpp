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

const int FLAG_SIZE = 1001000;
const int PRIME_SIZE = 80000;

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
    ll n;
    int i;
    while(1==scanf("%lld",&n))
    {
        set<int>st;
        ll temp = n;
        int x;
        for(i=1;prime[i]<=n/prime[i];i++)
        {
            while(n%prime[i]==0)
            {
                x = prime[i];
                n/=prime[i];
                st.insert(prime[i]);
            }
        }
        if(n!=1LL)
            st.insert(n);
        if(temp==n)
        {
            printf("%lld\n",n);
            continue;
        }
        if(st.size()==1)
        {
            printf("%d\n",x);
            continue;
        }
        printf("1\n");
    }

    return 0;
}
