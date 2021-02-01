#include<stdio.h>
int col[109];
int G[109][109];
int n,m;
bool dfs(int u)
{
    col[u]=1;
    bool cycle=0;
    int i,v;
    for(i=1;i<=n;i++)
    {
        if(G[u][i]==0)continue;
        v=i;
        if(col[v]==0){
            cycle|=dfs(v);
        }
        else if(col[v]==1){
            return 1;
        }
    }
    col[u]=2;
    return cycle;
}
int main()
{
    int i,j,x,u,v;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        G[u][v]=1;
    }
    bool cycle=0;
    for(i=1;i<=n;i++)
    {
        if(col[i]==0)
            cycle|=dfs(i);
    }
    if(cycle)
    printf("Cycle found !!\n");
    return 0;
}
/*
6 5
1 4
4 5
5 3
3 6
2 5

*/
