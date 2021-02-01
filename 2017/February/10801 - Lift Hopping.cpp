#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>

using namespace std;

#define OO          (1<<30)
#define pb          push_back

#define sqr(a)     (a*a)
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))

struct pq
{
    int n,t,l;
    bool operator <(const pq &b)const
    {
        return t>b.t;
    }
};

int dis[100][6],k,n,lt[6];
vector<int> ladj[6],adj[100];

int DIJKSTRA()
{
    int i,j,m,ch,l,f;
    pq u,v;
    priority_queue<pq>Q;

    u.n=0; u.t=0; u.l=1;
    Q.push(u);

    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();

        for(i=0;i<adj[u.n].size();i++)
        {
            printf("floor (u.n) -> %d\n",u.n);
            l = adj[u.n][i];
            printf("lift -> %d\n",l);

            for(j=0;j<ladj[l].size();j++)
            {
                f = ladj[l][j];
//                printf("floor -> %d\n",f);

                ch=60;

                if(!u.n || u.l == l)
                    ch=0;
//                printf("dis[f][l]-> %d\n",dis[f][l]);
                if(dis[f][l]>u.t+abs(u.n-f)*lt[l]+ch)
                {
                    v.t=dis[f][l]= u.t+abs(u.n-f)*lt[l]+ch;
                    v.n=f;
                    v.l=l;
//                    printf("v.t - > %d\nv.n-> %d\nv.l-> %d\n",v.t,v.n,v.l);
                    Q.push(v);
                }
            }
        }
    }
    m=OO;
    for(i=1;i<n+1;i++)
        m = min(m,dis[k][i]);

    return m;
}


int main()
{
    freopen("in.txt","r",stdin);

    int i,j,f,time;
    char a[1000];
    stringstream iss;

    while(scanf("%d%d",&n,&k)==2)
    {
        for(i=0;i<100;i++)
        {
            for(j=1;j<n+1;j++)
                dis[i][j] = OO;
            adj[i].clear();
        }
        for(i=1;i<n+1;i++)
            dis[0][i] = 0;

        for(i=1;i<n+1;i++)
            scanf("%d",&lt[i]);
        scanf("%c",&a[0]);

        for(i=1;i<n+1;i++)
        {
            gets(a);
            iss.clear();
            iss.str(a);
            ladj[i].clear();
            while(iss>>f)
            {
                ladj[i].pb(f);
                adj[f].pb(i);
            }
        }
        time= DIJKSTRA();
        if(time < OO)  printf("%d\n",time);
        else printf("IMPOSSIBLE\n");
    }

    return 0;
}
