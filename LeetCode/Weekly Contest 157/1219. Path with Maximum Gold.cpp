int dr[]={1, 0, 0,-1};
int dc[]={0,-1, 1, 0};
int vis[30][30];
int ar[30][30];
int ans,row,column;

void dfs(int r,int c,int sum)
{
    for(int i=0;i<4;i++)
    {
        if(r+dr[i]<row && c+dc[i]<column && r+dr[i]>=0 && c+dc[i]>=0
           && vis[r+dr[i]][c+dc[i]]==0 && ar[r+dr[i]][c+dc[i]]!=0)
        {
            vis[r+dr[i]][c+dc[i]]=1;
            dfs(r+dr[i],c+dc[i],sum+ar[r+dr[i]][c+dc[i]]);
        }
    }
    ans = max(ans,sum);
    vis[r][c]=0;
}

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int i,j,r,c;
        r = grid.size();
        c = grid[0].size();
        row = r;
        column = c;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                ar[i][j]=grid[i][j];
        ans = 0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                if(ar[i][j]!=0)
                {
                    vis[i][j]=1;
                    dfs(i,j,ar[i][j]);
                }
            }
        return ans;
    }
};
