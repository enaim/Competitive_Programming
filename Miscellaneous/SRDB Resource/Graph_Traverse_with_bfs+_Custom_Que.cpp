#include<iostream>
using namespace std;
int G[100][100];
int Discovery_time[100],n;
class Que
{
public:
    int Front_pos,Last_pos,arr[10000];
    Que()
    {
        Front_pos=0;
        Last_pos=0;
    }
    void Insert(int _)
    {
        arr[Last_pos++]=_;
    }
    bool Is_empty()
    {
        return Front_pos==Last_pos;
    }
    int Front()
    {
        if(Is_empty())
        {
            Front_pos=Last_pos=0;
            return 1e9;
        }
        return arr[Front_pos];
    }
    void Pop()
    {
        Front_pos++;
    }
};
void BFS(int u)
{
    Que Q;
    int time=0;
    Q.Insert(u);
    while(Q.Is_empty()==0)
    {
        int now=Q.Front();
        Q.Pop();
        if(Discovery_time[now]==0)
        Discovery_time[now]=++time;
        for(int i=1;i<=n;i++)
        {
            if(G[now][i]==0)continue;
            if(Discovery_time[i]==0)
            Q.Insert(i);
        }
    }
}
int main()
{
    int m,i,j,u,v,x;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        G[u][v]=1;
        G[v][u]=1;
    }
    BFS(1);
    for(i=1;i<=n;i++)cout<<Discovery_time[i]<<" ";

}
/*
7 7
7 2
2 3
3 4
4 6
6 1
1 5
5 3

*/
