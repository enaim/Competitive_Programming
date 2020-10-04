#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

const int Size = 100;

vector<int> adj[Size],weight[Size],parent[Size];
int dis[Size];
int V,E;

struct node{
    int ndNmbr;
    int dist;

     node(int ndNmbr=0,int dist=0){
        this->ndNmbr = ndNmbr;
        this->dist = dist;
    }

    // Me < notMe
    bool operator < (const node& notMe)const {
        return dist > notMe.dist;
    }
};

void Dijkstra(int Source)
{
    priority_queue<node>pq;

    for(int i=1;i<=V;i++)
        dis[i] = OO;

    dis[Source] = 0;
    pq.push(node(Source,0));
    parent[Source].pb(-1);

    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();

        int u = top.ndNmbr;

        if(dis[u] < top.dist)   continue;

        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            int w = weight[u][i];
            int currentCalculatedDistance = w + dis[u];

            if(dis[v] > currentCalculatedDistance)
            {
                parent[v].pb(u);
                dis[v] = currentCalculatedDistance;
                pq.push(node( v, currentCalculatedDistance));
            }
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,u,v,w,tks,a,b;
    int Source;
    V = 5;
    map<string,int>mp;
    mp["Dhaka"] = 1;
    mp["Chittagong"] = 2;
    mp["Rajshahi"] = 3;
    mp["Kathmandu"] = 4;
    mp["Butwal"] = 5;

    adj[1].pb(3);
    weight[1].pb(300);

    adj[1].pb(2);
    weight[1].pb(200);

    adj[3].pb(1);
    weight[3].pb(300);

    adj[2].pb(1);
    weight[2].pb(200);

    adj[2].pb(4);
    weight[2].pb(3000);

    adj[4].pb(2);
    weight[4].pb(3000);

    adj[2].pb(5);
    weight[2].pb(8000);

    adj[5].pb(2);
    weight[5].pb(8000);
    scanf("%d",&tks);
    string str1,str2;
    while(tks--)
    {
        cin>>str1>>str2;
        a = mp[str1];
        b = mp[str2];

        Dijkstra(a);

        printf("%d\n",dis[b]);
    }

    return 0;
}
