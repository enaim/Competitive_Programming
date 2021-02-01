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

vector<int>vec[200010];
int ar[200010];
int vis[200010];
int vis1[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,u,v,n,x,sz,cnt1,cnt2;

    while(1==scanf("%d",&n))
    {
        for(i=0;i<200010;i++)
        {
            vec[i].clear();
            vis[i]=0;
            vis1[i]=0;
        }

        queue<int>Q;
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            vec[v].pb(u);
            vec[u].pb(v);
        }

        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        if(ar[0] != 1)
        {
            printf("No\n");
            continue;
        }

        Q.push(1);
        cnt1 = 1;
        vis[1]=1;

        while(!Q.empty())
        {
            cnt2 = 0;
            u = Q.front();
            Q.pop();
            sz = vec[u].size();
            for(i=0;i<sz;i++)
            {
                v = vec[u][i];
                if(vis[v]==0)
                    vis1[v] = 1 , cnt2++;
            }
            x = 0;
            for(i=cnt1;i<cnt1+cnt2;i++)
            {
                v = ar[i];
                if(vis1[v]!=0)
                {
                    Q.push(v);
                    vis1[v]=0;
                    vis[v]=1;
                }
                else
                {
                    x  = 1;
                    break;
                }
            }

            if(x)
                break;

            cnt1 = cnt1+cnt2;
        }

        if(x)
            printf("No\n");
        else
            printf("Yes\n");
    }

    return 0;
}
