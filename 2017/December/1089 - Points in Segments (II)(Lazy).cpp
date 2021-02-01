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
const int SIZE = 150010;

int ar[SIZE];
int seg[SIZE];
int Q[SIZE];
int Tree[SIZE*4];
int Lazy[SIZE*4];


void lazy_update(int node_no,int lazy_val,int l,int r)
{
    Lazy[node_no] += lazy_val;
    Tree[node_no] += lazy_val;
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
    Tree[node_no] = 0;
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
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,e,n,s,x,y,ans,t,v,q;
    int tks,ks=1;
    scanf("%d",&tks);
    map<int,int>mp;
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        mp.clear();
        memset(Lazy,0,sizeof Lazy);
        memset(Tree,0,sizeof Tree);
        scanf("%d%d",&n,&q);
        for(i=1;i<=n*2;i+=2)
        {
            scanf("%d%d",&x,&y);
            seg[i] = x;
            seg[i+1] = y;
            ar[i] = x;
            ar[i+1] = y;;
        }
        for(j=1;j<=q;j++)
        {
            scanf("%d",&x);
            ar[i++] = x;
            Q[j]=x;
        }
        sort(&ar[1],&ar[i]);
        int cnt = 1;
        for(j=1;j<i;j++)
            mp[ar[j]] = cnt++;
        for(j=1;j<=n*2;j+=2)
            update(1,1,i-1,mp[seg[j]],mp[seg[j+1]],1);
        for(j=1;j<=q;j++)
            printf("%d\n",Query(1,1,i-1,mp[Q[j]],mp[Q[j]]));
    }

    return 0;
}
