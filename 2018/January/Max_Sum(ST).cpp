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
const int SIZE = 100;
int ar[SIZE];

struct node{
    int max_prefix,max_suffix,max_sum,total_sum;

    void Merge(node a,node b)
    {
        max_prefix = max(a.max_prefix ,a.total_sum + b.max_prefix);
        max_suffix = max(b.max_suffix ,b.total_sum + a.max_suffix);
        max_sum    = max(a.max_suffix + b.max_prefix ,max(a.max_sum , b.max_sum));
        total_sum  = a.total_sum + b.total_sum;
    }
};
node Tree[SIZE*4];

void update(int l,int r,int node_no,int pos)
{
    if(l==pos && r==pos)
    {
        Tree[node_no].max_prefix = ar[pos];
        Tree[node_no].max_suffix = ar[pos];
        Tree[node_no].total_sum  = ar[pos];
        Tree[node_no].max_sum    = ar[pos];
        return ;
    }
    int mid = (l+r)/2;
    int left = node_no*2;
    int right = node_no*2 + 1;

    if(pos<=mid)
        update(l,mid,node_no*2,pos);
    else
        update(mid+1,r,(node_no*2)+1,pos);

    Tree[node_no].Merge(Tree[left],Tree[right]);
}

node Query(int l,int r,int node_no,int s,int e)
{
    if(l==s && r==e)
        return Tree[node_no];
    int mid = (l+r)/2;
    if(e<=mid)
        return Query(l,mid,node_no*2,s,e);
    else if(s>mid)
        return Query(mid+1,r,(node_no*2)+1,s,e);
    else
    {
        node q1 = Query(l,mid,(node_no*2),s,mid);
        node q2 = Query(mid+1,r,(node_no*2)+1,mid+1,e);
        node x;
        x.Merge(q1,q2);
        return x;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,e,n,s,x,t;
    while(1==scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);

        for(i=1;i<=n;i++)
            update(1,n,1,i);

        while(true)
        {
            scanf("%d",&t);
            if(t==1)    //update
            {
                scanf("%d",&x);
                scanf("%d",&ar[x]);
                update(1,n,1,x);
            }
            else    //Query
            {
                scanf("%d%d",&s,&e);
                node ans = Query(1,n,1,s,e);
                printf("%d-%d -> %d\n",s,e,ans.max_sum);
            }
        }
    }

    return 0;
}
