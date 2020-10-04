#include<stdio.h>
#include<math.h>
#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>

using namespace std;

#define oo        (1<<30)
#define PI          3.141592653589793
#define ERR         1e-6
#define pi          2*acos(0)
#define pb          push_back
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))

template<class T>T sqr(T a) {return a*a;}

const int SIZE = 100;

struct coordinate
{
    double x,y;
};

coordinate hole[SIZE],gopher[SIZE];
bool colour[SIZE];
vector<int> l[SIZE];
int p[SIZE];

bool DFS(int u)
{
    int i,j;

    for(i=0;i<l[u].size();i++)
        if(colour[l[u][i]])
        {
            colour[l[u][i]] = false;

            if(p[ l[u][i] ]<0 || DFS(p[l[u][i]]))
            {
                p[l[u][i]] = u;
                return true;
            }
        }

    return false;
}

int main()
{
    freopen("in.txt","r",stdin);

    int i,c,j,n,m;
    double d,s,v;

    while(4==scanf("%d%d%lf%lf",&n,&m,&s,&v))
    {
        d = s*v;

        for(i=0;i<n;i++)
            scanf("%lf%lf",&gopher[i].x,&gopher[i].y);

        for(i=0;i<m;i++)
            scanf("%lf%lf",&hole[i].x,&hole[i].y);

        for(i=0;i<m;i++)
            l[i].clear();

        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if( sqrt(sqr(hole[i].x-gopher[j].x) + sqr(hole[i].y-gopher[j].y) ) < d ||
                   fabs(sqrt(sqr(hole[i].x-gopher[j].x) + sqr(hole[i].y-gopher[j].y)) - d ) < ERR )
                    {
                        l[i].pb(j);
                    }
            }

        c = 0;
        for(i=0;i<100;i++)
            p[i]= -1;

        for(i=0;i<m;i++)
        {
            for(j=0;j<100;j++)
                colour[j]= true;

            if(DFS(i))
                c++;
        }
        printf("%d\n",n-c);
    }

    return 0;
}
