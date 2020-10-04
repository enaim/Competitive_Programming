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
int Tree[SIZE*4];
int ans;

void update(int l,int r,int node_no,int s,int e)
{
    if(l==s && r==e)
    {
        Tree[node_no] += 1;
        return ;
    }
    int mid = (l+r)/2;
    if(e<=mid)
        update(l,mid,node_no*2,s,e);
    else if(s>mid)
        update(mid+1,r,(node_no*2)+1,s,e);
    else
    {
        update(l,mid,node_no*2,s,mid);
        update(mid+1,r,(node_no*2)+1,mid+1,e);
    }
}

void Query(int l,int r,int node_no,int s,int e)
{
    ans+=Tree[node_no];
    if(l==s && r==e)
        return;
    int mid = (l+r)/2;
    if(e<=mid)
        Query(l,mid,node_no*2,s,e);
    else if(s>mid)
        Query(mid+1,r,(node_no*2)+1,s,e);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,e,n,x,s,t,v,tks,ks=1,q;
    char str[SIZE],st[3];
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        scanf("%s",str);
        n = strlen(str);
        memset(Tree,0,sizeof Tree);

        scanf("%d",&q);
        while(q--)
        {
            scanf("%s",st);
            if(st[0]=='I')    //update
            {
                scanf("%d%d",&s,&e);
                update(1,n,1,s,e);
            }
            else    //Query
            {
                ans = 0;
                scanf("%d",&s);
                Query(1,n,1,s,s);
                if(ans%2==0)
                    printf("%c\n",str[s-1]);
                else
                {
                    x = str[s-1]-'0';
                    printf("%d\n",x^1);
                }
            }
        }
    }

    return 0;
}
