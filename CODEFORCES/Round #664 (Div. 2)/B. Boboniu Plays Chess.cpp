#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

int vis[110][110];
vector<int>vec;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,r,c,x,y;
    while(4==scanf("%d%d%d%d",&r,&c,&x,&y))
    {
        vis[x][y]=1;
        vec.pb(x);
        vec.pb(y);

        vis[1][y]=1;
        vec.pb(1);
        vec.pb(y);

        for(i=1;i<=r;i++)
        {
            if(i%2==1)
            {
                for(j=1;j<=c;j++)
                {
                    if(vis[i][j]==0)
                    {
                        vis[i][j]=1;
                        vec.pb(i);
                        vec.pb(j);
                    }
                }
            }
            if(i%2==0)
            {
                for(j=c;j>=1;j--)
                {
                    if(vis[i][j]==0)
                    {
                        vis[i][j]=1;
                        vec.pb(i);
                        vec.pb(j);
                    }
                }
            }
        }
        int sz = vec.size();
        for(i=0;i<sz;i+=2)
            printf("%d %d\n",vec[i],vec[i+1]);
    }

    return 0;
}
