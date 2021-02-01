int n;
int vis[5010];
int level[5010];
string str[5010];

int check(string s1, string s2)
{
    if(s1.size()!=s2.size())
        return 0;
    int cnt =  0;
    for(int i=0; i<s1.size(); i++)
    {
        if(s1[i]!=s2[i])
            cnt++;
    }
    return cnt;
}

int bfs(int u)
{
    vis[u]=1;
    level[u]=1;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0 && check(str[u],str[i])==1)
            {
                vis[i]=1;
                level[i]=level[u]+1;
                q.push(i);
                if(str[i]==str[n+1])
                    return level[i];
            }
        }
    }
    return 0;
}

class Solution
{
public:
    int ladderLength(string source, string target, vector<string>& words)
    {
        n = words.size();
        for(int i=0; i<=n+5; i++)
            vis[i]=0,level[i]=0;
        str[0] = source;
        str[n+1] = target;
        for(int i=1; i<=n; i++)
        {
            str[i]=words[i-1];
        }
        return bfs(0);
    }
};
