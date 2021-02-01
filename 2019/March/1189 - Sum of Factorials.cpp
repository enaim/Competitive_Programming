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

ll n;
ll fact[21];
vector<int>vec;

void factorial()
{
    ll i;
    fact[0]=1;
    for(i=1;i<=20;i++)
        fact[i]=fact[i-1]*i;
}

void go()
{
    int i = 20;
    while(i>=0)
    {
        if(n>=fact[i])
        {
            vec.pb(i);
            n-=fact[i];

        }
        i--;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    factorial();
    int tks,ks=1,x,sz,i;
    scanf("%d",&tks);
    while(tks--)
    {
        vec.clear();
        scanf("%lld",&n);

        go();
        if(n==0LL)
        {
            sz = vec.size();
            for(i=sz-1;i>=0;i--)
            {
                if(i==sz-1)
                    printf("Case %d: %d!",ks++,vec[i]);
                else
                    printf("+%d!",vec[i]);
            }
            printf("\n");
        }
        else
            printf("Case %d: impossible\n",ks++);
    }

    return 0;
}
