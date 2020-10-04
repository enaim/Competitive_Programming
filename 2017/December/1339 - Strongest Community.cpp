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

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const int SIZE = 100010;
int ar[SIZE];
int ar1[SIZE];
int sz[SIZE];
int Tree[SIZE*4];

struct Track{
int s,e;
};
Track se[SIZE];

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

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,e,n,s,x,y,ans,t,q,a,b,c;
    int tks,ks= 1;
    map<int,int>mp;
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        mp.clear();
        memset(sz,0,sizeof sz);
        memset(Tree,0,sizeof Tree);

        scanf("%d%d%d",&n,&c,&q);

        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            ar1[i] = x;

            if(!mp[x])
            {
                se[x].s = i;
                mp[x]++;
            }
            se[x].e = i;
            sz[x]++;
        }
        for(i=1;i<=c;i++)
        {
            for(j=se[i].s;j<=se[i].e;j++)
                ar[j]=sz[i];
        }

        for(i=1;i<=n;i++)
            update(1,n,1,i);

        while(q--)
        {
            scanf("%d%d",&i,&j);
            x = ar1[i];
            y = ar1[j];
            if(x==y)
            {
                a = 0;
                b = 0;
            }
            else
            {
                if(i==se[x].s)
                {
                    s = i;
                    a = 0;
                }
                else
                {
                    s = se[x].e + 1;
                    a = se[x].e - i + 1;
                }
                if(j==se[y].e)
                {
                    e = j;
                    b = 0;
                }
                else
                {
                    e = se[y].s - 1;
                    b = j - se[y].s + 1;
                }
            }
            if(s<e && x!=y)
                ans = Query(1,n,1,s,e);
            else if(x==y)
                ans = j-i+1;
            else
                ans = 0;
            ans = max(ans,max(a,b));

            printf("%d\n",ans);
        }
    }

    return 0;
}
