#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define OO (1<<25)

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

const int Size = 2100;

struct warmhole{
    int x;
    int y;
    int t;
};

warmhole ar[Size];
int dis[Size];
int n,m;

bool Bellman_Ford()
{
    warmhole e;
    bool update;

    for(int i=1;i<=n;i++)
        dis[i] = OO;

    for(int i=0;i<n;i++)
    {
        update = false;

        for(int j=0;j<m;j++)
        {
            e = ar[j];
            if(dis[e.y] > dis[e.x] + e.t)
            {
                dis[e.y] = dis[e.x] + e.t;
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


    int tks,ks=1,i;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
            scanf("%d%d%d",&ar[i].x,&ar[i].y,&ar[i].t);
        bool isnegative = Bellman_Ford();

        if(isnegative)
            printf("possible\n");
        else
            printf("not possible\n");
    }

    return 0;
}

