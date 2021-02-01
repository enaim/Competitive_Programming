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

char str[510][510];
int ar[510][510];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int r,c,i,j,k,cnt=0,x,y1,y2;
        sf2(r,c);
        for(i=0;i<r;i++)
            ssf(str[i]);

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                ar[i][j]=0;
                if(str[i][j]=='*')
                {
                    cnt++;
                }
            }
        }
        for(i=r-2;i>=0;i--)
        {
            for(j=0;j<c;j++)
            {
                if(str[i][j]=='*')
                {
                    if(j-1>=0 && j+1<c)
                    {
                        if(str[i+1][j-1]=='*' && str[i+1][j]=='*' && str[i+1][j+1]=='*')
                            ar[i][j]=1+min(ar[i+1][j-1],min(ar[i+1][j],ar[i+1][j+1]));
                    }
                }
            }
        }
        for(i=r-2;i>=0;i--)
            for(j=0;j<c;j++)
                cnt+=ar[i][j];
        pf(cnt);
    }

    return 0;
}
