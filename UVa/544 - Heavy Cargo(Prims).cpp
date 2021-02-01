#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

const int SIZE = 210;

vector<int> adj[SIZE],weight[SIZE];
int dis[SIZE],par[SIZE];
int V,E,X,Y,mn;
int colour[SIZE];

struct node{
    int ndNmbr;
    int dist;

     node(int ndNmbr=0,int dist=0){
        this->ndNmbr = ndNmbr;
        this->dist = dist;
    }

    // Me < notMe
    bool operator < (const node& notMe)const {
        return dist < notMe.dist;
    }
};

void Prims(int Source)
{
    priority_queue<node>pq;

    for(int i=1;i<=V;i++)
    {
        dis[i] = 0;
        colour[i]=false;
    }

    dis[Source] = OO;
    par[Source] = -1;
    pq.push(node(Source,OO));

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
            int currentCalculatedDistance = w ;
            if(dis[v] < currentCalculatedDistance && (colour[v] == false))
            {
                dis[v] = currentCalculatedDistance;
                pq.push(node( v, currentCalculatedDistance));
                par[v] = u;
            }
        }
        colour[u] = true;;
    }
}

int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int W,i,c,u,v,ks = 1,parent;
    char s1[40],s2[40];

    map<string,int>mp;

    while(2 == scanf("%d%d",&V,&E) &&V &&E)
    {
        mp.clear();
        c = 1;
        for(i=0;i<E;i++)
        {
            scanf("%s%s%d",s1,s2,&W);
            if(!mp[s1])
                mp[s1]=c++;
            if(!mp[s2])
                mp[s2]=c++;

            u = mp[s1];         v = mp[s2];

            adj[u].pb(v);
            adj[v].pb(u);
            weight[u].pb(W);
            weight[v].pb(W);
        }
        scanf("%s%s",s1,s2);
        X = mp[s1];
        Y = mp[s2];

        Prims(X);

        parent = Y;
        mn = dis[parent];
        while(parent != X)
        {
            parent = par[parent];
            if(mn > dis[parent])
                mn = dis[parent];
        }

        printf("Scenario #%d\n",ks++);
        printf("%d tons\n\n",mn);
    }

    return 0;
}
