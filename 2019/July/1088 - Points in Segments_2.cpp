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
const int SIZE = 200010;
int ar[SIZE];
int Tree[SIZE*4];
map<int,int>mp;

void update(int l,int r,int node_no,int pos)
{
    if(l==pos && r==pos)
    {
        Tree[node_no]=1;
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

struct query{
    int s,e;
};
query Q[50010];
set<int>st;
set<int>:: iterator it;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,e,n,s,x,ans,t,q;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        st.clear();
        mp.clear();
        memset(Tree,0,sizeof Tree);

        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);
            st.insert(ar[i]);
        }
        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&Q[i].s,&Q[i].e);
            st.insert(Q[i].s);
            st.insert(Q[i].e);
        }
        int cnt = 1;
        for(it=st.begin();it!=st.end();it++)
            mp[*it] = cnt++;
        for(i=1;i<=n;i++)
            update(1,cnt-1,1,mp[ar[i]]);

        printf("Case %d:\n",ks++);
        for(i=1;i<=q;i++)
        {
            ans = Query(1,cnt-1,1,mp[Q[i].s],mp[Q[i].e]);
            printf("%d\n",ans);
        }
    }

    return 0;
}
