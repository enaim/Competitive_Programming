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
const int SIZE = 100010;
int ar[SIZE],x;
int Tree[SIZE*4];

void update(int l,int r,int node_no,int pos,int v)
{
    if(l==pos && r==pos)
    {
        Tree[node_no]= v;
        return ;
    }
    int mid = (l+r)/2;
    if(pos<=mid)
        update(l,mid,node_no*2,pos,v);
    else
        update(mid+1,r,(node_no*2)+1,pos,v);

    Tree[node_no] = max(Tree[node_no*2],Tree[(node_no*2)+1]);
}

int Query(int l,int r,int node_no,int s,int e)
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
        int q1 = Query(l,mid,(node_no*2),s,mid);
        int q2 = Query(mid+1,r,(node_no*2)+1,mid+1,e);
        return max(q1,q2);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,e,n,s,ans,t,sz=100000;
    while(1==scanf("%d",&n))
    {
        memset(Tree,0,sizeof Tree);
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);

        for(i=n;i>=1;i--)
        {
            x = Query(1,sz,1,ar[i]+1,sz);
            update(1,sz,1,ar[i],x+1);
        }
        ans = Query(1,sz,1,1,sz);
        printf("%d\n",ans);
    }

    return 0;
}
