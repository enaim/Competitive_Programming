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
#define OO (1<<25)
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

ll Tree[SIZE*4];
ll Lazy[SIZE*4];

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

    int mid = (l+r)/2;
    int left = node_no*2;
    int right = node_no*2 + 1;

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

ll Query(ll l,ll r,ll node_no,ll s,ll e)
{
    if(l==s && r==e)
        return Tree[node_no];

    int mid = (l+r)/2;
    int left = node_no*2;
    int right = node_no*2 + 1;

    if(Lazy[node_no] != INF)
    {
        lazy_update(left,Lazy[node_no],l,mid);
        lazy_update(right,Lazy[node_no],mid+1,r);
        Lazy[node_no] = INF;
    }

    if(e<=mid)
        return Query(l,mid,left,s,e);
    else if(s>mid)
        return Query(mid+1,r,right,s,e);
    else
    {
        ll q1 = Query(l,mid,left,s,mid);
        ll q2 = Query(mid+1,r,right,mid+1,e);
        return q1+q2;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,e,n,s,x,ans,t,v,tks,q,ks=1;
    scanf("%lld",&tks);
    while(tks--)
    {
        memset(Tree,0,sizeof Tree);
        memset(Lazy,0,sizeof Lazy);

        scanf("%lld%lld",&n,&q);

        while(q--)
        {
            scanf("%lld",&t);
            if(t==0)    //update
            {
                scanf("%lld%lld",&s,&e);
                scanf("%lld",&v);
                update(1,1,n,s,e,v);
            }
            else    //Query
            {
                scanf("%lld%lld",&s,&e);
                ans = Query(1,n,1,s,e);
                printf("%lld\n",ans);
            }
        }
    }

    return 0;
}
