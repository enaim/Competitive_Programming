//given an array .. In every query answer will be number of element which are less then x from left to right

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

struct node{
    int l,r,ind;
};

const double pi = acos(-1.0);
const double eps = 1e-8;
const int SIZE = 100010;
int ar[SIZE];
int Tree[SIZE*4];
vector<node>vec[SIZE];
vector<int>num[SIZE];

void update(int l,int r,int node_no,int pos)
{
    if(l==pos && r==pos)
    {
        Tree[node_no]= 1;
        return ;
    }
    int mid = (l+r)/2;

    if(pos<=mid)
        update(l,mid,node_no*2,pos);
    else
        update(mid+1,r,(node_no*2)+1,pos);

    Tree[node_no] = Tree[node_no*2] + Tree[(node_no*2)+1];
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
        return q1+q2;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n,x,q,ks=0;
    int ans[100010];
    node a;
    while(2==scanf("%d%d",&n,&q))
    {
        memset(Tree,0,sizeof Tree);
        for(i=0;i<SIZE;i++)
        {
            vec[i].clear();
            num[i].clear();
        }

        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            num[x].pb(i);
        }
        while(q--)
        {
            ks++;
            scanf("%d%d%d",&a.l,&a.r,&x);
            a.ind = ks;
            vec[x].pb(a);
        }

        for(i=0;i<100000;i++)
        {
            int sz = vec[i].size();
            for(j=0;j<sz;j++)
            {
                a = vec[i][j];
                if(i==0)
                {
                    ans[a.ind] = 0;
                    continue;
                }
                ans[a.ind] = Query(1,n,1,a.l,a.r);
            }
            sz = num[i].size();
            for(j=0;j<sz;j++)
                update(1,n,1,num[i][j]);
        }

        for(i=1;i<=ks;i++)
            printf("%d\n",ans[i]);
    }

    return 0;
}
