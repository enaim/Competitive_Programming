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
#define OO (1<<25)

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

int V,E;
int dis[100];

struct Graph{
    int u;
    int v;
    int w;
};

Graph Edge[100];


bool Bellman_Ford(int Source)
{
    Graph e;
    int i,j;
    bool update;

    for(i=1;i<=V;i++)
        dis[i] = OO;

    dis[Source] = 0;

    for(i=0;i<V;i++)
    {
        update = false;
        for(j=0;j<E;j++)
        {
            e = Edge[j];
            if(dis[e.v] > dis[e.u] + e.w);
            {
                dis[e.v] = dis[e.u] + e.w;
                update = true;
            }
        }
    }

    return update;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,Source;

    while(3==scanf("%d%d%d",&V,&E,&Source))
    {
        for(i=0;i<E;i++)
        {
            scanf("%d%d%d",&Edge[i].u,&Edge[i].v,&Edge[i].w);
        }

        bool isNegativeWeightCycle = Bellman_Ford(Source);
        if(isNegativeWeightCycle)
            puts("Negative Weight Cycle Exists!");
        else
        {
                for(i=1;i<=V;i++)
            printf("dis[%d] - > %d\n",i,dis[i]);
        }

    }

    return 0;
}

