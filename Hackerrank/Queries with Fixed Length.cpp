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
int ar[SIZE];
int Tree[SIZE*4];

void build(int l,int r,int node_no)
{
    if (l == r) {
        Tree[node_no] = ar[l];
        return;
    }
    int Left = node_no * 2;
    int Right = node_no * 2 + 1;
    int mid = (l + r) / 2;
    build(l,mid,Left);
    build(mid + 1,r,Right);
    Tree[node_no] = max(Tree[Left],Tree[Right]);
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

    int i,e,n,s,x,ans,t,q,mn,d;
    while(2==scanf("%d%d",&n,&q))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);

        build(1,n,1);

        while(q--)
        {
            scanf("%d",&d);
            mn = OO;
            for(i=1;i<=n-d+1;i++)
            {
                ans = Query(1,n,1,i,i+d-1);
                mn = min(mn,ans);
            }
            printf("%d\n",mn);
        }
    }

    return 0;
}
