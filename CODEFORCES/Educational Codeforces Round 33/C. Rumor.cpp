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
#define sqr(a)  (a*a)

typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const int Size = 100010;

struct rom{
    int x,y;
};

rom ar[Size];
bool flag[Size];
int ar1[Size];
vector<int>vec[Size];

bool compare(rom a,rom b)
{
    return a.x<b.x;
}

void colour(int x)
{
    flag[x]=false;
    int sz = vec[x].size();
    for(int i=0;i<sz;i++)
    {
        int u = vec[x][i];
        if(flag[u]==true)
            colour(u);
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,sz,u,v,j,k,n,temp,mn;

    while(2==scanf("%d%d",&n,&k))
    {
        long long ans = 0;
        memset(flag,true,sizeof flag);

        for(i=0;i<Size;i++)
            vec[i].clear();

        for(i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            ar[i].x = temp;
            ar[i].y = i;
            ar1[i] = temp;
        }

        sort(&ar[1],&ar[n+1],compare);

        for(i=0;i<k;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
        }

        ans = 0;
        for(i=1;i<=n;i++)
        {
            mn = ar[i].x;
            u = ar[i].y;

            if(flag[u]==false)
                continue;

            sz = vec[u].size();

            for(j=0;j<sz;j++)
                if(mn>ar1[vec[u][j]])
                    mn = ar1[vec[u][j]];
            ans += mn;

            colour(u);
        }

        for(i=1;i<=n;i++)
        {
            if(flag[i])
                ans+=ar1[i];
        }

        printf("%lld\n",ans);
    }

    return 0;
}
