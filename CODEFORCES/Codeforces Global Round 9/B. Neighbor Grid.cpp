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

int dr[]={1, 0, 0,-1};
int dc[]={0,-1, 1, 0};

int ar[310][310];
int br[310][310];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int n,m,i,j,k,a,b;
        sf2(n,m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                sf(ar[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                int cnt = 0;
                for(k=0;k<4;k++)
                {
                    a = dr[k]+i;
                    b = dc[k]+j;
                    if(a>=0 && a<n && b>=0 && b<m)
                        cnt++;
                }
                br[i][j]=cnt;
            }

        int flag = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(ar[i][j]>br[i][j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
        {
            puts("NO");
        }
        else
        {
            puts("YES");
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    printf("%d ",br[i][j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
