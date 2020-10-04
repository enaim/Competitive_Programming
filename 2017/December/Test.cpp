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
const int SIZE = 1450000;
int ar[SIZE];
int Tree[SIZE*4];
int num;


void update1(int l,int r,int node_no,int pos)
{
    if(l==pos && r==pos)
    {
        Tree[node_no][0]=1;
        Tree[node_no][1]= num;
        return ;
    }
    int mid = (l+r)/2;
    if(pos<=mid)
        update(l,mid,node_no*2,pos);
    else
        update(mid+1,r,(node_no*2)+1,pos);
    Tree[node_no][0] = Tree[node_no*2][0] + Tree[(node_no*2)+1][0];
}

void update(int l,int r,int node_no,int pos)
{
    if(l==pos && r==pos)
    {
        Tree[node_no]= 0;
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
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,e,n,s,x,ans,t;
    int tks,ks=1;
    num = 1;
    for(i=1;i<1450000;i++)
    {
        update1(1,n,1,i);
        num+=2;
    }
    ans = 1;
    for(i=2;i<=100000;i++)
    {
        Query(1,n,1,i,i);
    }
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            update(1,n,1,i);
    }

    return 0;
}
