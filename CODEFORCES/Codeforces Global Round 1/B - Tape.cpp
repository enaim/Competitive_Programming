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

ll n,k,x,m,y,sum,ans;

struct node{
    ll dif,ind;
};

struct ss{
    ll x,y;
};
ss t[100010];
node ar[100010];
int f[100010];
ll arr[100010];

bool compare(node a,node b)
{
    return a.dif>b.dif;
}

bool compare1(node a,node b)
{
    return a.ind<b.ind;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i;

    while(3==scanf("%lld%lld%lld",&n,&m,&k))
    {
        i = 0;
        scanf("%lld",&arr[i]);
        ar[i].dif = 0;
        ar[i].ind = 0;
        for(i=1;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            ar[i].dif = arr[i]-arr[i-1]+1;
            ar[i].ind = i;
            x = y;
        }
        if(k>=n)
        {
            printf("%lld\n",n);
            continue;
        }
        if(n==1LL)
        {
            printf("0\n");
            continue;
        }
        if(k==1LL)
        {
            printf("%lld\n",arr[n-1]-arr[0]+1);
            continue;
        }
        sort(&ar[0],&ar[n],compare);

        for(i=0;i<k-1;i++)
            f[ar[i].ind]=1;
        sort(&ar[0],&ar[n],compare1);

        ans = 0LL;

        int cnt=0;
        t[cnt].x=arr[0];
        t[cnt].y=arr[0];
        for(i=0;i<n;i++)
        {
            if(f[i]==0)
                t[cnt].y=arr[i];
            else
            {
                cnt++;
                t[cnt].x=arr[i];
                t[cnt].y=arr[i];
            }
        }
        for(i=0;i<=cnt;i++)
            ans+=(t[i].y-t[i].x+1);

        printf("%lld\n",ans);
    }

    return 0;
}
