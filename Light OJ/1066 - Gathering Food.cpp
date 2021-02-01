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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

int dr[]={1, 0, 0,-1};
int dc[]={0,-1, 1, 0};

struct node{
    int x,y,z;
};
node ar[30];

int k,n,cnt;
int vis[12][12];
char str[12][12];

int BFS()
{
    node v,t,nxt;
    int i;
    v = ar[0];
    nxt = ar[cnt];
    str[v.x][v.y]='.';
    vis[v.x][v.y]=1;

    queue<node>Q;
    Q.push(v);
    while(!Q.empty())
    {
        v = Q.front();
        Q.pop();

        for(i=0;i<4;i++)
        {
            t.x = v.x + dr[i];
            t.y = v.y + dc[i];
            t.z = v.z + 1;
            if(t.x>=0 && t.x<n && t.y>=0 && t.y<n)
            {
                if(t.x==nxt.x && t.y==nxt.y)
                {
                    memset(vis,0,sizeof vis);
                    while(!Q.empty())
                        Q.pop();

                    ar[cnt].z=t.z;
                    cnt++;

                    if(cnt == k)
                        break;
                    nxt = ar[cnt];
                    str[t.x][t.y]='.';
                    vis[t.x][t.y]=1;
                    Q.push(t);
                    break;
                }
                else if(vis[t.x][t.y]==0 && str[t.x][t.y]=='.')
                {
                    vis[t.x][t.y]=1;
                    Q.push(t);
                }
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,ch;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(vis,0,sizeof vis);

        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",str[i]);

        k = 0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(str[i][j]>='A' && str[i][j]<='Z')
                {
                    ch = str[i][j]-'A';
                    ar[ch].x=i;
                    ar[ch].y=j;
                    ar[ch].z=0;
                    k++;
                }
            }

        cnt = 1;
        if(k>1)
            BFS();
        if(cnt==k)
            printf("Case %d: %d\n",ks++,ar[k-1].z);
        else
            printf("Case %d: Impossible\n",ks++);
    }

    return 0;
}
