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

int ar[100010];
int flag[100010];
vector<int>vec[100010];

int dfs(int v)
{
    int sz = vec[v].size();
    int cnt = 0;
    for(int i=0;i<sz;i++)
    {
        int u = vec[v][i];
        dfs(u);
        if(ar[u])
            cnt++;
    }
    if(cnt==sz && ar[v]==1)
        flag[v]=1;
    else
        flag[v]=0;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i,p,root;
    while(1==scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&p,&ar[i]);
            if(p==-1)
                root = i;
            vec[p].pb(i);
        }
        dfs(root);
        int f = 1;
        for(i=1;i<=n;i++)
            if(flag[i]==1 && i!=root)
                printf("%d ",i),f=0;
        if(f)
            printf("-1");
        printf("\n");
    }

    return 0;
}
