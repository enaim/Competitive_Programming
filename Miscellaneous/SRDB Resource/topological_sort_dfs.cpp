#include<iostream>
using namespace std;
class Vector
{
public:
    int _last;
    int arr[110];
    void Push(int _)
    {
        arr[_last++]=_;
    }
    void Pop()
    {
        arr[_last--]=0;
    }
};
int G[110][110],res[110],vis[110];
int n,m;
Vector V;
void Reset()
{
    for(int i=0; i<=100; i++){
        V.arr[i]=0;
        vis[i]=0;
        for(int j=0;j<=100;j++)G[i][j]=0;
    }
    V._last=0;
}
void dfs(int u)
{
    vis[u]=1;
    int i;
    for(i=1; i<=n; i++)
    {
        int v=i;
        if(vis[v]==0 && G[u][v]==1)
            dfs(v);
    }
    V.Push(u);
}
int main()
{
    while(cin>>n>>m)
    {
        if(n==0 && m==0)break;
        int i,j,u,v;
        Reset();
        for(i=1; i<=m; i++)
        {
            cin>>u>>v;
            G[u][v]=1;
        }

        for(i=1; i<=n; i++)
        {
            if(vis[i]==0)dfs(i);
        }

        for(i=n-1; i>=0; i--)
        {
            cout<<V.arr[i];
            if(i>0)cout<<" ";
        }
        cout<<endl;
    }
}
