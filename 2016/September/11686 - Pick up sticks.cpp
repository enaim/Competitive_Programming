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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const int SIZE = 1000010;

vector<int>adj[SIZE];
queue<int>Q;

int k,V,E;
int degree[SIZE],TS[SIZE];

void BFS()
{
    int temp,u;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            temp = adj[u][i];
            degree[temp]--;
            if(degree[temp]==0)
            {
                TS[k++]=temp;
                Q.push(temp);
            }
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,u,v;
    while(2==scanf("%d%d",&V,&E) && (V || E))
    {
        k = 0;
        for(i=0;i<=V;i++)
        {
            degree[i]=0;
            TS[i]=0;
            adj[i].clear();
        }

        for(i=0;i<E;i++)
        {
            scanf("%d%d",&v,&u);
            adj[v].pb(u);
            degree[u]++;
        }

        for(i=1;i<=V;i++)
        {
            if(degree[i] == 0)
            {
                Q.push(i);
                TS[k++]=i;
            }
        }

        BFS();
        if(k==V)
            for(i=0;i<k;i++)
                printf("%d\n",TS[i]);
        else
            printf("IMPOSSIBLE\n");
    }

    return 0;
}
