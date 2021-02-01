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

struct node{
    int x,y,l,u,r,d;
};
node ar[200010];
int n;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,xmax,xmin,ymax,ymin;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        xmax = ymax = -OO;
        xmin = ymin = OO;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d%d%d",&ar[i].x,&ar[i].y,&ar[i].l,&ar[i].u,&ar[i].r,&ar[i].d);
            xmin = min(xmin,ar[i].x);
            ymin = min(ymin,ar[i].y);
            xmax = max(xmax,ar[i].x);
            ymax = max(ymax,ar[i].y);
        }

        for(i=0;i<n;i++)
        {
            if(ar[i].l==0)
                xmin = max(xmin,ar[i].x);
            if(ar[i].u==0)
                ymax = min(ymax,ar[i].y);
            if(ar[i].r==0)
                xmax = min(xmax,ar[i].x);
            if(ar[i].d==0)
                ymin = max(ymin,ar[i].y);
        }
        if(xmin>xmax || ymin>ymax)
            cout<<0<<endl;
        else
            cout<<1<<" "<<xmin<<" " <<ymin<<endl;
    }

    return 0;
}
