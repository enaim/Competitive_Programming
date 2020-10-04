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


int cnt;
int ar[10010];
int colour[10010];
int visited[10010];
vector<int>vec[100010];

void func(int v,int cl)
{
    int i;
    int sz = vec[v].size();
    for(i=0;i<sz;i++)
    {
        int u = vec[v][i];
        if(visited[u] != 1 && colour[u] != cl)
        {
            colour[u]=cl;
            func(u,cl);
        }
    }
}

void func1(int v,int cl)
{
    int i,u;
    visited[v]=1;
    if(colour[v]!=cl)
    {
        colour[v] = cl;
        cnt++;
        func(v,cl);
    }
    int sz = vec[v].size();
    for(i=0;i<sz;i++)
    {
        u = vec[v][i];
        if(!visited[u])
            func1(u,ar[u]);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,v;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<10010;i++)
            vec[i].clear();
        memset(colour,0,sizeof colour);
        memset(visited,0,sizeof visited);

        for(i=2;i<=n;i++)
        {
            scanf("%d",&v);
            vec[i].pb(v);
            vec[v].pb(i);
        }
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);
        cnt = 0;
        func1(1,ar[1]);
        printf("%d\n",cnt);
    }

    return 0;
}
