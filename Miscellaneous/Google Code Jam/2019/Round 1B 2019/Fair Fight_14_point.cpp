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
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

const int SIZE = 110;
int ar[SIZE];
int Tree[SIZE*4];

void update(int l,int r,int node_no,int pos)
{
    if(l==pos && r==pos)
    {
        Tree[node_no]= ar[pos];
        return ;
    }
    int mid = (l+r)/2;
    if(pos<=mid)
        update(l,mid,node_no*2,pos);
    else
        update(mid+1,r,(node_no*2)+1,pos);

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

int ar1[SIZE];
int Tree1[SIZE*4];

void update1(int l,int r,int node_no,int pos)
{
    if(l==pos && r==pos)
    {
        Tree1[node_no]= ar1[pos];
        return ;
    }
    int mid = (l+r)/2;
    if(pos<=mid)
        update1(l,mid,node_no*2,pos);
    else
        update1(mid+1,r,(node_no*2)+1,pos);

    Tree1[node_no] = max(Tree1[node_no*2],Tree1[(node_no*2)+1]);
}

int Query1(int l,int r,int node_no,int s,int e)
{
    if(l==s && r==e)
        return Tree1[node_no];
    int mid = (l+r)/2;
    if(e<=mid)
        return Query1(l,mid,node_no*2,s,e);
    else if(s>mid)
        return Query1(mid+1,r,(node_no*2)+1,s,e);
    else
    {
        int q1 = Query1(l,mid,(node_no*2),s,mid);
        int q2 = Query1(mid+1,r,(node_no*2)+1,mid+1,e);
        return max(q1,q2);
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,x,y,j,n,k;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);

        for(i=1;i<=n;i++)
            scanf("%d",&ar1[i]);

        for(i=1;i<=n;i++)
            update(1,n,1,i);

        for(i=1;i<=n;i++)
            update1(1,n,1,i);

        int cnt = 0;
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
            {
                x = Query(1,n,1,i,j);
                y = Query1(1,n,1,i,j);
                if(abs(x-y)<=k)
                    cnt++;
            }

        printf("Case #%d: %d\n",ks++,cnt);
    }


    return 0;
}
