#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

struct node{
    int x,y,dis;
    node(int x,int y,int dis=0)
    {
        this->x = x;
        this->y = y;
        this->dis = dis;
    }
};

int vis[110][110];
char str[110][110];
int r,x1,x2,y2,i,y;

int bfs(node u)
{
    int mn = 100000000;
    vis[u.x][u.y]=1;
    queue<node>st;
    st.push(u);
    while(!st.empty())
    {
        u = st.front();
        st.pop();
        for(i=u.y;i<r;i++)
        {
            if(str[u.x][i]=='X')
                break;

            if(vis[u.x][i]==0)
            {
                vis[u.x][i] = 1;
                if(u.x==x2 && i==y2)
                    mn = min(mn,u.dis+1);

                st.push(node(u.x,i,u.dis+1));
            }
        }

        for(i=u.y;i>=0;i--)
        {
            if(str[u.x][i]=='X')
                break;
            if(vis[u.x][i]==0)
            {
                vis[u.x][i] = 1;
                if(u.x==x2 && i==y2)
                    mn = min(mn,u.dis+1);

                st.push(node(u.x,i,u.dis+1));
            }
        }

        for(i=u.x;i<r;i++)
        {
            if(str[i][u.y]=='X')
                break;
            if(vis[i][u.y]==0)
            {
                vis[i][u.y] = 1;
                if(i==x2 && u.y==y2)
                    mn = min(mn,u.dis+1);

                st.push(node(i,u.y,u.dis+1));
            }
        }

        for(i=u.x;i>=0;i--)
        {
            if(str[i][u.y]=='X')
                break;
            if(vis[i][u.y]==0)
            {
                vis[i][u.y] = 1;
                if(i==x2 && u.y==y2)
                    mn = min(mn,u.dis+1);

                st.push(node(i,u.y,u.dis+1));
            }
        }
    }
    return mn;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&r))
    {
        for(i=0;i<r;i++)
            scanf("%s",str[i]);

        scanf("%d%d%d%d",&x1,&y,&x2,&y2);
        cout<<bfs(node(x1,y))<<endl;
    }

    return 0;
}
