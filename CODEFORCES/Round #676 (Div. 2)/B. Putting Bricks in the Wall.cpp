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
    int x,y,val;
};

char str[210][210];
vector<node>vec;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        vec.clear();
        node a,b,c,d;
        int i,n;
        sf(n);
        for(i=0;i<n;i++)
            ssf(str[i]);
        a.x = 0;
        a.y = 1;
        a.val = str[a.x][a.y]-'0';

        b.x = 1;
        b.y = 0;
        b.val = str[b.x][b.y]-'0';

        c.x = n-1;
        c.y = n-2;
        c.val = str[c.x][c.y]-'0';

        d.x = n-2;
        d.y = n-1;
        d.val = str[d.x][d.y]-'0';

        if(a.val == b.val)
        {
            if(a.val == c.val)
                vec.pb(c);
            if(a.val == d.val)
                vec.pb(d);
        }
        else if(c.val==d.val)
        {
            if(a.val == c.val)
                vec.pb(a);
            if(b.val == c.val)
                vec.pb(b);
        }
        else
        {
            if(a.val==1)
                vec.pb(b);
            else
                vec.pb(a);
            if(c.val==0)
                vec.pb(d);
            else
                vec.pb(c);
        }
        pf(vec.size());
        for(i=0;i<vec.size();i++)
            pf2(vec[i].x+1,vec[i].y+1);
    }

    return 0;
}
