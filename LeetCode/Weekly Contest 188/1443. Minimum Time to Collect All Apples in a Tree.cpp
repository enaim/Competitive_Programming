vector<int>vec[100010];
int dis[100010];
bool ap[100010];
int apple;

void dfs(int u,int p)
{
    if(ap[u])
        apple++;
    int sz = vec[u].size();
    for(int i=0;i<sz;i++)
    {
        int temp = apple;
        if(vec[u][i]==p)
            continue;
        dfs(vec[u][i],u);
        if(temp!=apple)
            dis[u]+=2;
    }
}


class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int i,sum=0;
        for(i=0;i<100010;i++)
        {
            dis[i]=0;
            vec[i].clear();
        }
        apple = 0;

        for(i=0;i<n;i++)
            ap[i]=hasApple[i];
        for(i=0;i<edges.size();i++)
        {
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(0,-1);

        for(i=0;i<100010;i++)
            sum+=dis[i];
        return sum;
    }
};
