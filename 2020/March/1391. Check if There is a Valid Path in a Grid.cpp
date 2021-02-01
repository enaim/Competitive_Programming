int ar[310][310];
int vis[310][310];
int m,n,r,c,f;

void dfs(int x,int y)
{
    if(x==r-1 && y==c-1)
        f = 1;
    int nx1,ny1,nx2,ny2;
    vis[x][y]=1;
    if(ar[x][y]==1)
    {
        nx1 = x;
        ny1 = y-1;

        nx2 = x;
        ny2 = y+1;

        if(nx1>=0 && nx1<r && ny1>=0 && ny1<c && vis[nx1][ny1]==0 && (ar[nx1][ny1]==1 || ar[nx1][ny1]==4 || ar[nx1][ny1]==6))
            dfs(nx1,ny1);
        if(nx2>=0 && nx2<r && ny2>=0 && ny2<c && vis[nx2][ny2]==0 && (ar[nx2][ny2]==1 || ar[nx2][ny2]==3 || ar[nx2][ny2]==5))
            dfs(nx2,ny2);
    }
    if(ar[x][y]==2)
    {
        nx1 = x-1;
        ny1 = y;

        nx2 = x+1;
        ny2 = y;

        if(nx1>=0 && nx1<r && ny1>=0 && ny1<c && vis[nx1][ny1]==0 && (ar[nx1][ny1]==2 || ar[nx1][ny1]==3 || ar[nx1][ny1]==4))
            dfs(nx1,ny1);
        if(nx2>=0 && nx2<r && ny2>=0 && ny2<c && vis[nx2][ny2]==0 && (ar[nx2][ny2]==2 || ar[nx2][ny2]==5 || ar[nx2][ny2]==6))
            dfs(nx2,ny2);

    }
    if(ar[x][y]==3)
    {
        nx1 = x;
        ny1 = y-1;

        nx2 = x+1;
        ny2 = y;

        if(nx1>=0 && nx1<r && ny1>=0 && ny1<c && vis[nx1][ny1]==0 && (ar[nx1][ny1]==1 || ar[nx1][ny1]==4 || ar[nx1][ny1]==6))
            dfs(nx1,ny1);
        if(nx2>=0 && nx2<r && ny2>=0 && ny2<c && vis[nx2][ny2]==0 && (ar[nx2][ny2]==2 || ar[nx2][ny2]==5 || ar[nx2][ny2]==6))
            dfs(nx2,ny2);

    }
    if(ar[x][y]==4)
    {
        nx1 = x;
        ny1 = y+1;

        nx2 = x+1;
        ny2 = y;

        if(nx1>=0 && nx1<r && ny1>=0 && ny1<c && vis[nx1][ny1]==0 && (ar[nx1][ny1]==1 || ar[nx1][ny1]==3 || ar[nx1][ny1]==5))
            dfs(nx1,ny1);
        if(nx2>=0 && nx2<r && ny2>=0 && ny2<c && vis[nx2][ny2]==0 && (ar[nx2][ny2]==2 || ar[nx2][ny2]==5 || ar[nx2][ny2]==6))
            dfs(nx2,ny2);

    }
    if(ar[x][y]==5)
    {
        nx1 = x;
        ny1 = y-1;

        nx2 = x-1;
        ny2 = y;

        if(nx1>=0 && nx1<r && ny1>=0 && ny1<c && vis[nx1][ny1]==0 && (ar[nx1][ny1]==1 || ar[nx1][ny1]==4 || ar[nx1][ny1]==6))
            dfs(nx1,ny1);
        if(nx2>=0 && nx2<r && ny2>=0 && ny2<c && vis[nx2][ny2]==0 && (ar[nx2][ny2]==2 || ar[nx2][ny2]==3 || ar[nx2][ny2]==4))
            dfs(nx2,ny2);

    }
    if(ar[x][y]==6)
    {
        nx1 = x;
        ny1 = y+1;

        nx2 = x-1;
        ny2 = y;

        if(nx1>=0 && nx1<r && ny1>=0 && ny1<c && vis[nx1][ny1]==0 && (ar[nx1][ny1]==1 || ar[nx1][ny1]==3 || ar[nx1][ny1]==5))
            dfs(nx1,ny1);
        if(nx2>=0 && nx2<r && ny2>=0 && ny2<c && vis[nx2][ny2]==0 && (ar[nx2][ny2]==2 || ar[nx2][ny2]==3 || ar[nx2][ny2]==4))
            dfs(nx2,ny2);

    }
}

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        memset(vis,0,sizeof vis);
        r = grid.size();
        c = grid[0].size();
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                  ar[i][j]=grid[i][j];
        f = 0;
        dfs(0,0);
        if(f==1)
            return true;
        return false;
    }
};

