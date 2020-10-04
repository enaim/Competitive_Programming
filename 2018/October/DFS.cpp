#include<bits/stdc++.h>
using namespace std;

bool vis[100010];
vector<int>adj[100010];

void DFS(int u)
{
    printf("%d ",u);
    vis[u]=false;

    int sz = adj[u].size();
    for(int i=0;i<sz;i++)
    {
        int v = adj[u][i];
        if(vis[v])
            DFS(v);
    }
}

int main()
{
    int V,E,u,v;
    while(2==scanf("%d%d",&V,&E))
    {
        for(int i=0;i<100010;i++)
        {
            vis[i]=true;
            adj[i].clear();
        }
        for(int i=0;i<E;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        DFS(1);
        printf("\n");
    }

    return 0;
}
