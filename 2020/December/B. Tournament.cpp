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

struct node{
    int x,y;
};
int deg[60];
node ar[3000];
vector<int>vec,lose1,win2;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n,m,a,b;
    while(1==scanf("%d",&n))
    {
        memset(deg,0,sizeof deg);
        m = (n*(n-1))/2;
        m--;
        for(i=0;i<m;i++)
        {
            sf2(a,b);
            ar[i].x = a;
            ar[i].y = b;
            deg[a]++;
            deg[b]++;
        }
        vec.clear();
        for(i=1;i<=n;i++)
        {
            if(deg[i]==n-2)
                vec.pb(i);
        }
        lose1.clear();
        win2.clear();
        for(i=0;i<m;i++)
        {
           if(ar[i].x==vec[0])
               lose1.pb(ar[i].y);
           if(ar[i].y==vec[1])
               win2.pb(ar[i].x);
        }
        int flag = 0;
        for(i=0;i<lose1.size();i++)
        {
            for(j=0;j<win2.size();j++)
            {
                if(lose1[i]==win2[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            pf2(vec[0],vec[1]);
        else
            pf2(vec[1],vec[0]);
    }

    return 0;
}

