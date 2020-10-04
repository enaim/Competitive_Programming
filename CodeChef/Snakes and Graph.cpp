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


const int SIZE = 100010;
const int Size = 200010;


struct edge{

	int u,v,w;
};


int n,m;
edge ar[Size];
int deg[SIZE];
int rnk[SIZE],parent[SIZE];
vector<int>vec;


bool compare(edge a,edge b)
{
	return a.w>b.w;
}


int Find_Set(int x)
{
    if(x != parent[x])
        parent[x] = Find_Set(parent[x]);

    return parent[x];
}

void Link(int x,int y)
{
    if(rnk[x] > rnk[y])
        parent[y] = x;
    else
    {
        parent[x] = y;

        if(rnk[x] == rnk[y])
            rnk[y]++;
    }
}

void Union(int x,int y)
{
    Link(Find_Set(x),Find_Set(y));
}

void Make_Set(int x)
{
    parent[x] = x;
    rnk[x] = 0;
}

void MST_KRUSKAL()
{
    int i,j,cnt;
    for(i=1;i<=n;i++)
        Make_Set(i);

	sort(&ar[0],&ar[m],compare);

	cnt = n-1;
	i = 0;

    for(j=n-1;j>=0;j--)
	{
		vec.pb(cnt);
		while(ar[i].w == j && i<m)
		{
			if(Find_Set(ar[i].u) != Find_Set(ar[i].v))
	        {
	            cnt--;
	            Union(ar[i].u,ar[i].v);
	        }
	        i++;
		}
	}
}






int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

	int tks,i;

	scanf("%d",&tks);

	while(tks--)
	{
		vec.clear();
		memset(deg,0,sizeof deg);
		scanf("%d%d",&n,&m);

		for(i=0;i<m;i++)
		{
			scanf("%d%d",&ar[i].u,&ar[i].v);
			deg[ar[i].u]++;
			deg[ar[i].v]++;
		}


		for(i=0;i<m;i++)
		{
			if(deg[ar[i].u]>deg[ar[i].v])
				ar[i].w = deg[ar[i].v];
			else
				ar[i].w = deg[ar[i].u];
		}

		MST_KRUSKAL();

		for(i=vec.size()-1;i>=0;i--)
		{
			if(i == vec.size()-1)
				printf("%d",vec[i]);
			else
				printf(" %d",vec[i]);

		}
		printf("\n");
	}


    return 0;
}
