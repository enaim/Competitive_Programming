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
    ll v,ind;
};

bool compare(node a,node b)
{
    return a.v<b.v;
}

node ar[200010];
vector<ll>vec;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,i,sum,cnt;

    while(1==scanf("%lld",&n))
    {
        vec.clear();
        sum = 0;
        for(int i = 1;i<=n;i++)
        {
            scanf("%lld",&ar[i].v);
            ar[i].ind=i;
            sum+=ar[i].v;
        }
        sort(&ar[1],&ar[n+1],compare);

        cnt = 0;
        for(i=1;i<n;i++)
        {
            if(sum-ar[n].v-ar[i].v==ar[n].v)
            {
                cnt++;
                vec.pb(ar[i].ind);
            }
        }
        if(sum-ar[n].v-ar[n-1].v==ar[n-1].v)
        {
            cnt++;
            vec.pb(ar[n].ind);
        }
        printf("%lld\n",cnt);
        if(cnt==0)
        {
            printf("\n");
            continue;
        }
        for(i=0;i<cnt;i++)
            printf("%lld ",vec[i]);
    }

    return 0;
}
