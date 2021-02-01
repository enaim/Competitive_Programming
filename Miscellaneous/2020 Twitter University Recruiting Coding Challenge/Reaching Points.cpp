#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'canReach' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER y1
 *  3. INTEGER x2
 *  4. INTEGER y2
 */

struct node{
    int x,y;
};

node d;
int flag;
int vis[2010][2010];

bool check(node v)
{
    if(v.x==d.x && v.y==d.y)
        return true;
    return false;
}

void bfs(node u)
{
    queue<node>Q;
    Q.push(u);
    vis[u.x][u.y]=1;
    if(check(u))
    {
        flag = 1;
        return;
    }
    int ks = 1;
    while(!Q.empty())
    {
        node v = Q.front();
        Q.pop();
        node temp;
        temp.x = v.x+v.y;
        temp.y = v.y;
        if(temp.x<1200 && temp.y<1200)
        if(vis[temp.x][temp.y]==0)
        {
            vis[temp.x][temp.y]=1;
            if(check(temp))
            {
                flag = 1;
                return;
            }
            Q.push(temp);
        }
        temp.x = v.x;
        temp.y = v.x+v.y;
        if(temp.x<1200 && temp.y<1200)
        if(vis[temp.x][temp.y]==0)
        {
            vis[temp.x][temp.y]=1;
            if(check(temp))
            {
                flag = 1;
                return;
            }
            Q.push(temp);
        }
    }
    return;
}

string canReach(int x1, int y1, int x2, int y2) {
    memset(vis,0,sizeof vis);
    flag = 0;
    node u;
    u.x = x1;
    u.y = y1;
    d.x = x2;
    d.y = y2;
    bfs(u);
    if(flag)
        return "Yes";
    return "No";
}

int main()
