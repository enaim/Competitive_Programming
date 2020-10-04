#include<bits/stdc++.h>
using namespace std;

bool vis[100010];
vector<int>adj[100010];

void BFS(int start)
{
    queue<int>Q;
    Q.push(start);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        vis[u]=false;
        printf("%d ",u);

        int sz = adj[u].size();
        for(int i=0;i<sz;i++)
        {
            int v = adj[u][i];
            if(vis[v])
                Q.push(v);
        }
    }
    printf("\n");
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
        BFS(1);
    }

    return 0;
}
