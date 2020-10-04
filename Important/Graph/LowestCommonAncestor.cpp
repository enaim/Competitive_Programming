#include<bits/stdc++.h>
using namespace std;

const int Size = 100010;

int E,V;
int L[Size];
int par[Size];
int A[Size][20];
vector<int>adj[Size];

void Leveling()
{
    queue<int>Q;
    Q.push(1);
    L[1]=1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int sz = adj[u].size();
        for(int i=0;i<sz;i++)
        {
            int v = adj[u][i];
            L[v] = L[u]+1;
            Q.push(v);
        }
    }
}

void Sparse_Table()
{
    // creating sparse table
    for(int p=0;p<20;p++)
    {
        for(int i=1;i<=V;i++)
        {
            if(p==0)
                A[i][p] = par[i];
            else
                A[i][p] = A[A[i][p-1]][p-1];
        }
    }
}

int LCA(int u,int v)
{
    if(L[u]>L[v])
        swap(u,v);
    //Bring u and v in same level
    for(int i=19;i>=0;i--)
    {
        int x = A[v][i];
        if(L[u]==L[x])
        {
            v=x;
            break;
        }
        if(L[u]<L[x])
            v = x;
    }

    if(u==v)
        return u;


    for(int i=19;i>=0;i--)
    {
        int uu = A[u][i];
        int vv = A[v][i];
        if(uu != -1 && uu != vv)
        {
            u = uu;
            v = vv;
        }
    }

    return par[u];
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,u,v,q;

    while(2==scanf("%d%d",&V,&E))
    {
        for(i=0;i<Size;i++)
        {
            adj[i].clear();
            for(j=0;j<20;j++)
                A[i][j] = -1;
        }
        par[1] = 0;
        for(i=0;i<E;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            par[v] = u;
        }

        Leveling();
        Sparse_Table();

        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&u,&v);
            printf("%d\n",LCA(u,v));
        }
    }

    return 0;
}
