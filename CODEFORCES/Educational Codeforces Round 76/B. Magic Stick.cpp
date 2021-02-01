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

queue<ll>Q;
map<ll,int>mp;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll x,y;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        while(!Q.empty())
            Q.pop();

        mp.clear();
        ll x,y;
        scanf("%lld%lld",&x,&y);
        if(x+y==2LL || x>=y)
        {
            printf("YES\n");
            continue;
        }
        if(x==1)
        {
            printf("NO\n");
            continue;
        }
        int f = 0;
        Q.push(x);
        ll temp = x;
        while(!Q.empty())
        {
            ll it = Q.front();
            Q.pop();
            if(it>=y)
            {
                f = 1;
                break;
            }
            if(it%2LL==1LL)
                it = it-1LL;
            x = (it/2LL)*3LL;
            if(x>=y)
            {
                f = 1;
                break;
            }
            if(mp[x]==0)
                Q.push(x);
            mp[x]++;
        }
        if(f)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
