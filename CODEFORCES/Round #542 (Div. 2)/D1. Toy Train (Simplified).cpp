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

vector<int>vec[5010],v;
int i,j,m,n,x,szz,mx,s,e,sum,ind;
int sz[5010];
int ar[5010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&m))
    {
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&s,&e);
            vec[s].pb(e);
            sz[s]++;
        }
        for(i=1;i<=n;i++)
        {
            int z = OO;
            for(j=0;j<sz[i];j++)
            {
                int t;

                if(vec[i][j]>=i)
                    t = vec[i][j]-i;
                else
                    t = n+vec[i][j]-i;
                if(z>t)
                {
                    z = t;
                    ind = vec[i][j];
                }
            }
            if(sz[i]!=0)
                vec[i][0]=ind;
        }
        for(i=1;i<=n;i++)
        {
            x = i;
            sum = 0;
            mx = sz[i];
            if(mx==0)
                continue;
            if(vec[x][0]>=x)
                sum = ((mx-1)*n)+(vec[x][0]-x);
            else
                sum = ((mx-1)*n)+(vec[x][0]+n-x);
            ar[x]=sum;
        }
        for(i=1;i<=n;i++)
        {
            int ans = 0;
            for(j=1;j<=n;j++)
            {
                x = j;
                if(ar[x]==0)
                    continue;
                if(x>=i)
                    ans = max(ans,x-i+ar[x]);
                else
                    ans = max(ans,n+x-i+ar[x]);
            }
            printf("%d ",ans);
        }
        printf("\n");
    }

    return 0;
}
