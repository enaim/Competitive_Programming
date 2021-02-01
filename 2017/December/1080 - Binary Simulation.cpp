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

    int i,e,n,x,ans,s,t,v,tks,ks=1,q;
    char str[SIZE],st[3];
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        scanf("%s",str);
        n = strlen(str);
        memset(Tree,0,sizeof Tree);
        memset(Lazy,0,sizeof Lazy);

        scanf("%d",&q);
        while(q--)
        {
            scanf("%s",st);
            if(st[0]=='I')    //update
            {
                scanf("%d%d",&s,&e);
                update(1,1,n,s,e,1);
            }
            else    //Query
            {
                scanf("%d",&s);
                ans = Query(1,1,n,s,s);
                if(ans%2==0)
                    printf("%c\n",str[s-1]);
                else
                {
                    x = str[s-1]-'0';
                    printf("%d\n",x^1);
                }
            }
        }
    }

    return 0;
}
