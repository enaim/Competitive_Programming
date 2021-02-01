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
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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
vector<int>vec[1010];
int ar[1010];
int vis[1010];

void go(int k)
{
    int sz = vec[k].size();
    int cnt = 0;
    for(int i=0;i<sz;i++)
    {
        int u = vec[k][i];
        if(!vis[u])
        {
            go(u);
        }
        vis[u] = 1;
        if(ar[u]==0)
            cnt++;
    }
    ar[k]=cnt;
    vis[k] = 1;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int n,i,x;
    while(1==scanf("%d",&n))
    {
        memset(ar,0,sizeof ar);
        memset(vis,0,sizeof vis);
        for(i=0;i<1010;i++)
            vec[i].clear();
        for(i=2;i<=n;i++)
        {
            scanf("%d",&x);
            vec[x].pb(i);
        }
        int z = 0;
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
                go(i);
            if(vec[i].size() && ar[i]<3)
                z = 1;
        }
        if(z)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
