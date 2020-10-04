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

int ar1[SIZE];
int prev[SIZE];
int ans[SIZE];
int Tree[SIZE*4];
vector<int>vec[SIZE],qnum[SIZE];

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

    int i,j,e,n,s,x,sz,temp,u,q;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        for(i=0;i<SIZE;i++)
        {
            vec[i].clear();
            qnum[i].clear();
            prev[i]=0;
        }
        memset(Tree,0,sizeof Tree);

        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
            scanf("%d",&ar1[i]);

        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&s,&e);
            vec[e].pb(s);
            qnum[e].pb(i);
        }
        for(i=1;i<=n;i++)
        {
            temp = ar1[i];
            if(prev[temp] > 0)
            {
                x = prev[temp];
                update(1,n,1,x,0);
            }

            prev[temp] = i;
            update(1,n,1,i,1);

            sz =vec[i].size();
            for(j=0;j<sz;j++)
            {
                u = vec[i][j];
                x = qnum[i][j];
                ans[x] = Query(1,n,1,u,i);
            }
        }
        for(i=1;i<=q;i++)
            printf("%d\n",ans[i]);
    }

    return 0;
}
