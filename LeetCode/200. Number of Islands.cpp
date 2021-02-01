struct node{
  int r,c;
};
bool vis[310][310];
int ar[310][310];
int row, column;

int dr[]={ 0 ,0, +1, -1};
int dc[]={-1,+1,  0,  0};

bool check(int rw, int cl)
{
  if(rw>=0 && rw<row && cl>=0 && cl<column)
    return true;
  return false;
}

void bfs(node source)
{
  queue<node>q;
  q.push(source);
  vis[source.r][source.c]=true;
  while(!q.empty())
  {
    source = q.front();
    q.pop();
    for(int k=0;k<4;k++)
    {
      int adjacentRow = source.r + dr[k];
      int adjacentColumn = source.c + dc[k];

      if(check(adjacentRow, adjacentColumn)==true && ar[adjacentRow][adjacentColumn]==1
         && vis[adjacentRow][adjacentColumn]==false)
      {
        node adjacent;
        adjacent.r = adjacentRow;
        adjacent.c = adjacentColumn;
        vis[adjacentRow][adjacentColumn]=true;
        q.push(adjacent);
      }
    }
  }
  return;
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        column = grid[0].size();
        for(int i=0;i<row+5;i++)
            for(int j=0;j<column+5;j++)
                vis[i][j]=false;
        int i,j;
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
                ar[i][j]=grid[i][j]-'0';
         }

        int islandCount = 0;
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                if(ar[i][j]==1 && vis[i][j]==false)
                {
                  islandCount++;
                  node source;
                  source.r = i;
                  source.c = j;
                  bfs(source);
                }
                else
                vis[i][j]=true;
            }
        }
        return islandCount;
    }
};
