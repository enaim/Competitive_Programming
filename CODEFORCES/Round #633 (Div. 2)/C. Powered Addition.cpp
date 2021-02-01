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

ll ar[100010];
ll i,n,limit;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i]);
        limit = ar[0];
        ll need = 0LL;
        for(i=1;i<n;i++)
        {
            if(limit<=ar[i])
                limit = ar[i];
            else
                need = max(need,limit-ar[i]);
        }
        ll sum = 0LL;
        i = 0LL;
        if(need>0LL)
        for(i=1;i<=60;i++)
        {
            ll x = (1<<(i-1));
            x = max(0LL,x);
            sum+=x;
            if(sum>=need)
                break;
        }
        cout<<i<<endl;
    }

    return 0;
}
