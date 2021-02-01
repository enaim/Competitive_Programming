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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e+5
#define sqr(a)  (a*a)

typedef long long ll;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double pi = acos(-1.0);
const double eps = 1e-8;
const int INF = 0;
const int SIZE = 100010;

ll ar[SIZE];
ll sum[SIZE*4];
ll Tree[SIZE*4];
ll Lazy[SIZE*4];

void build(int l,int r,int node_no)
{
    if (l == r) {
        Tree[node_no] = ar[l];
        return;
    }
    int Left = node_no * 2;
    int Right = node_no * 2 + 1;
    int mid = (l + r) / 2;
    build(l,mid,Left);
    build(mid + 1,r,Right);
    Tree[node_no] = Tree[Left] + Tree[Right];
}

void lazy_update(ll node_no,ll lazy_val,ll l,ll r)
{
    Lazy[node_no] += lazy_val;
    Tree[node_no] += lazy_val*(r-l+1);
}

void update(ll node_no,ll l,ll r,ll s,ll e,ll v)
{
    if(l==s && r==e)
    {
        lazy_update(node_no,v,l,r);
        return;
    }

    ll mid = (l+r)/2;
    ll left = node_no*2;
    ll right = node_no*2 + 1;

    if(Lazy[node_no] != INF)
    {
        lazy_update(left,Lazy[node_no],l,mid);
        lazy_update(right,Lazy[node_no],mid+1,r);
        Lazy[node_no] = INF;
    }

    if(e<=mid)
        update(left,l,mid,s,e,v);
    else if(s>mid)
        update(right,mid+1,r,s,e,v);
    else
    {
        update(left,l,mid,s,mid,v);
        update(right,mid+1,r,mid+1,e,v);
    }
    Tree[node_no] = Tree[left]+ Tree[right];
}

ll Query(ll node_no,ll l,ll r,ll s,ll e)
{
    if(l==s && r==e)
        return Tree[node_no];

    ll mid = (l+r)/2;
    ll left = node_no*2;
    ll right = node_no*2 + 1;

    if(Lazy[node_no] != INF)
    {
        lazy_update(left,Lazy[node_no],l,mid);
        lazy_update(right,Lazy[node_no],mid+1,r);
        Lazy[node_no] = INF;
    }

    if(e<=mid)
        return Query(left,l,mid,s,e);
    else if(s>mid)
        return Query(right,mid+1,r,s,e);
    else
    {
        int q1 = Query(left,l,mid,s,mid);
        int q2 = Query(right,mid+1,r,mid+1,e);
        return q1+q2;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,e,n,s,x,t,v,tks,m,q,y,ks=1;
    scanf("%lld",&tks);
    while(tks--)
    {
        printf("Case %lld:\n",ks++);

        memset(Lazy,0,sizeof Lazy);

        scanf("%lld%lld%lld",&n,&m,&q);
        for(i=1;i<=n;i++)
            scanf("%lld",&ar[i]);

        build(1,n,1);

        sum[0]=0;
        for(i=1;i<=m;i++)
        {
            scanf("%lld",&x);
            sum[i] = sum[i-1] + x;
        }

        while(q--)
        {
            scanf("%lld%lld",&x,&y);
            scanf("%lld%lld",&s,&e);
            update(1,1,n,s,e,sum[y]-sum[x-1]);
        }

        for(i=1;i<=n;i++)
        {
            ll ans = Query(1,1,n,i,i);
            if(i==n)
                printf("%lld\n",ans);
            else
                printf("%lld ",ans);
        }
    }

    return 0;
}
