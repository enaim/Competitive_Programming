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

struct node{
    ll x,y;
};

node ar[47000];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,sum,i,cnt;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        for(i=1LL;i*i<=n;i++)
        {
            ar[i].x=i;
            ar[i].y=n/i;
        }
        cnt = i-1;
        sum = 0;
        for(i=1;i<cnt;i++)
        {
            sum+=((ar[i+1].x-ar[i].x)*ar[i].y);
            sum+=((ar[i].y-ar[i+1].y)*ar[i].x);
        }
        if(ar[i].x==ar[i].y)
            sum+=ar[i].x;
        else
            sum+=(((ar[i].y-ar[i].x)*ar[i].x)+ar[i].y);

        printf("Case %d: %lld\n",ks++,sum);
    }

    return 0;
}
