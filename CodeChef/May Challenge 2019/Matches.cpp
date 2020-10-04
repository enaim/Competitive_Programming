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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

int func(ll n, ll m,int k)
{
    if(n==0LL | m==0LL)
        return !k;
    int x,y;
    x = y = -1;
    if(n<m)
        swap(n,m);
    x = func(n%m,m,!k);
    if(n>m*2)
        y = func((n%m)+m,m,!k);
    if(x==k || y==k)
        return k;
    return !k;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,m;
    int tks,ks=1,cnt;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&m);
        if(func(n,m,1)==1)
            printf("Ari\n");
        else
            printf("Rich\n");
    }

    return 0;
}
