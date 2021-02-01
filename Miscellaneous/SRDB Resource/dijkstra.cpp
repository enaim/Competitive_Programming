#include<iostream>
using namespace std;
int n,m,x,y,z;
int G[110][110];
int dis[110];
bool vis[110];
int FindMin(){
    int mn=1e9,idx;
    for(int i=1;i<=n;i++){
        if(dis[i]<mn && vis[i]==0){
            idx=i;mn=dis[i];
        }
    }
    return idx;
}
void dijkstra(int src){
    dis[src]=0;
    for(int i=1;i<n;i++){
        int mn=FindMin();
        vis[mn]=1;
        for(int j=1;j<=n;j++){
            if(vis[j]==0 && G[mn][j]&& dis[mn]!=1e9&& dis[mn]+G[mn][j]<dis[j])
                dis[j]=dis[mn]+G[mn][j];
        }
    }
    for(int i=1;i<=n;i++)cout<<i<<" "<<dis[i]<<endl;
}
int main(){
    cin>>n>>m;
    while(m--){
        cin>>x>>y>>z;
        G[x][y]=G[y][x]=z;
    }
    for(int i=0;i<=100;i++)dis[i]=1e9;
    dijkstra(1);
}
/*
4 4
1 2 6
1 3 9
2 4 5
3 4 1
*/

