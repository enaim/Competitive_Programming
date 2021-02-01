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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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
    int x,y,ind;
};
node ar[100010];
int flag[100010];
int i,j,n,l,r;

bool compare(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&ar[i].x,&ar[i].y);
            ar[i].ind = i;
        }
        sort(&ar[0],&ar[n],compare);
        l = ar[0].x;
        r = ar[0].y;
        flag[ar[0].ind]=1;
        for(i=1 ;i<n;i++)
        {
            if(r<ar[i].x)
                break;
            r = max(ar[i].y,r);
            flag[ar[i].ind]=1;
        }
        for(j=i;j<n;j++)
            flag[ar[j].ind]=2;

        if(i==n)
            printf("-1\n");
        else
        {
            for(i=0;i<n;i++)
            {
                if(i==n-1)
                    printf("%d\n",flag[i]);
                else
                    printf("%d ",flag[i]);
            }
        }
    }

    return 0;
}
