//1135 - Count the Multiples of 3
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

int Tree[SIZE*4][4];
int Lazy[SIZE*4];


void lazy_update(int node_no,int l_v,int l,int r)
{
    Lazy[node_no] += l_v;
    int temp0 = Tree[node_no][0];
    int temp1 = Tree[node_no][1];
    int temp2 = Tree[node_no][2];
    Tree[node_no][(0+l_v)%3] = temp0;
    Tree[node_no][(1+l_v)%3] = temp1;
    Tree[node_no][(2+l_v)%3] = temp2;
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
    Tree[node_no][0] = Tree[left][0] + Tree[right][0];
    Tree[node_no][1] = Tree[left][1] + Tree[right][1];
    Tree[node_no][2] = Tree[left][2] + Tree[right][2];

}

int Query(int node_no,int l,int r,int s,int e)
{
    if(l==s && r==e)
        return Tree[node_no][0];

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
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,e,n,s,x,ans,q,v,t;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        memset(Lazy,0,sizeof Lazy);
        for(i=1;i<SIZE*4;i++)
        {
            Tree[i][0] = 1;
            Tree[i][1] = 0;
            Tree[i][2] = 0;
        }
        scanf("%d%d",&n,&q);

        for(i=1;i<=n;i++)
            update(1,1,n,i,i,0);

        while(q--)
        {
            scanf("%d",&t);
            if(t==0)    //update
            {
                scanf("%d%d",&s,&e);
                update(1,1,n,s+1,e+1,1);
            }
            else    //Query
            {
                scanf("%d%d",&s,&e);
                ans = Query(1,1,n,s+1,e+1);
                printf("%d\n",ans);
            }
        }
    }

    return 0;
}
