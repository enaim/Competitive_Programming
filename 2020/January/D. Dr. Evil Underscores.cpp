#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

int tree[3000010][2];
int node;

void ins(int val)
{
    int cur = 0;
    for(int i=29;i>=0;i--)
    {
        if(val&(1<<i))
        {
            if(tree[cur][1]==0)
                tree[cur][1]=++node;
            cur = tree[cur][1];
        }
        else
        {
            if(tree[cur][0]==0)
                tree[cur][0]=++node;
            cur = tree[cur][0];
        }
    }
}

int go(int pos,int cur)
{
    if(pos==-1)
        return 0;
    if(tree[cur][0]!=0 && tree[cur][1]!=0)
        return min((1<<pos)+go(pos-1,tree[cur][0]),(1<<pos)+go(pos-1,tree[cur][1]));
    if(tree[cur][0]!=0)
        return go(pos-1,tree[cur][0]);
    if(tree[cur][1]!=0)
        return go(pos-1,tree[cur][1]);
    return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout)

    int i,n,x;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            ins(x);
        }
        cout<<go(29,0)<<endl;
    }

    return 0;
}
