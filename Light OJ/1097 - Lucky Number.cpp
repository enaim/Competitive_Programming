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
const int SIZE = 1450010;

int ar[SIZE];
int Tree[SIZE*4][2];
int ans[100010];
int num,cnt = 0;


void Build(int l,int r,int node_no,int pos)
{
    if(l==pos && r==pos)
    {
        Tree[node_no][0] = 1;
        Tree[node_no][1] = num;
        return ;
    }
    int mid = (l+r)/2;
    if(pos<=mid)
        Build(l,mid,node_no*2,pos);
    else
        Build(mid+1,r,(node_no*2)+1,pos);

    Tree[node_no][0] = Tree[node_no*2][0] + Tree[(node_no*2)+1][0];
}


void update(int l,int r,int node_no,int v)
{
    if(Tree[node_no][0] == v && Tree[node_no][1])
    {
        Tree[node_no][0] = 0;
        return ;
    }
    int mid = (l+r)/2;
    if(Tree[node_no*2][0]>=v)
        update(l,mid,node_no*2,v);
    else
        update(mid+1,r,(node_no*2)+1,v-Tree[node_no*2][0]);
    Tree[node_no][0] = Tree[node_no*2][0] + Tree[(node_no*2)+1][0];
}


int Query(int l,int r,int node_no,int v)
{
    if(Tree[node_no][0]==v && Tree[node_no][1])
        return Tree[node_no][1];
    int mid = (l+r)/2;
    if(Tree[node_no*2][0]>=v)
        return Query(l,mid,node_no*2,v);
    else
        return Query(mid+1,r,(node_no*2)+1,v-Tree[node_no*2][0]);
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,x,sum,n=1450000;
    int tks,ks=1;
    num = 1;
    for(i=1;i<=n;i++)
    {
        Build(1,n,1,i);
        num+=2;
    }

    sum = n;
    ans[1] = 1;
    for(i=2;i<=100000;i++)
    {
        ans[i] = Query(1,n,1,i);
        x = ans[i];
        while(x<=sum)
        {
            update(1,n,1,x);
            x+=ans[i];
            x--;
            sum--;
        }
    }

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&x);
        printf("Case %d: %d\n",ks++,ans[x]);
    }

    return 0;
}
