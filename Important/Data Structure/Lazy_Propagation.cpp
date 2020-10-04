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
const int INF = OO;
const int SIZE = 100;

int ar[SIZE];
int Tree[SIZE*4];
int Lazy[SIZE*4];


void lazy_update(int node_no,int lazy_val,int l,int r)
{
    Lazy[node_no] = lazy_val;
    Tree[node_no] = lazy_val*(r-l+1);
//    Tree[node_no] = lazy_val;
}

void update(int node_no,int l,int r,int s,int e,int v)
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
//    Tree[node_no] = min(Tree[left],Tree[right]);
//    Tree[node_no] = max(Tree[left],Tree[right]);
}

int Query(int node_no,int l,int r,int s,int e)
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
        return Query(left,l,mid,s,e);
    else if(s>mid)
        return Query(right,mid+1,r,s,e);
    else
    {
        int q1 = Query(left,l,mid,s,mid);
        int q2 = Query(right,mid+1,r,mid+1,e);
        return q1+q2;
//        return min(q1,q2);
//        return max(q1,q2);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,e,n,s,x,ans,t,v;
    while(1==scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);

        for(i=1;i<=n;i++)
            update(1,1,n,i,i,ar[i]);

        while(true)
        {
            scanf("%d",&t);
            if(t==1)    //update
            {
                scanf("%d%d",&s,&e);
                scanf("%d",&v);
                update(1,1,n,s,e,v);
            }
            else    //Query
            {
                scanf("%d%d",&s,&e);
                ans = Query(1,1,n,s,e);
                printf("%d-%d -> %d\n",s,e,ans);
            }
        }
    }

    return 0;
}
