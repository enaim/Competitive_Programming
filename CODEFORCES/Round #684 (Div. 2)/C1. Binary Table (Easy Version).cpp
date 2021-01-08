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

bool compare(node a, node b)
{
    return a.val<b.val;
}

vector<node>vec;
vector<node>vec1;
vector<node>vec2;
vector<node>vec3;
vector<node>vec4;
vector<node>ans;

vector<node> one(node a, node b, node c, node d)
{
    vec1.clear();
    vec1.pb(b); vec1.pb(c); vec1.pb(d);
    return vec1;
}

vector<node> two(node a, node b, node c, node d)
{
    vec2.clear();
    vec2.pb(a); vec2.pb(b); vec2.pb(c);
    vec2.pb(a); vec2.pb(b); vec2.pb(d);
    return vec2;
}

vector<node> three(node a, node b, node c, node d)
{
    vec3.clear();
    vec3.pb(a); vec3.pb(b); vec3.pb(c);
    vec3.pb(a); vec3.pb(b); vec3.pb(d);
    vec3.pb(a); vec3.pb(b); vec3.pb(c);
    vec3.pb(a); vec3.pb(c); vec3.pb(d);
    vec3.pb(b); vec3.pb(c); vec3.pb(d);
    return vec3;
}

vector<node> zero(node a, node b, node c, node d)
{
    vec4.clear();
    vec4.pb(a); vec4.pb(b); vec4.pb(d);
    vec4.pb(a); vec4.pb(b); vec4.pb(c);
    vec4.pb(a); vec4.pb(c); vec4.pb(d);
    vec4.pb(b); vec4.pb(c); vec4.pb(d);
    return vec4;
}

node temp[4];
char str[110][110];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,r,c,sum,k;
        ans.clear();
        sf2(r,c);
        for(i=0;i<r;i++)
            ssf(str[i]);

        for(i=0;i<r-1;i++)
        {
            for(j=0;j<c;j+=2)
            {
                if(j==c-1)
                    j--;

                temp[0].x = i+1;
                temp[0].y = j+1;
                temp[0].val = str[i][j]-'0';

                temp[1].x = i+1;
                temp[1].y = j+2;
                temp[1].val = str[i][j+1]-'0';

                temp[2].x = i+2;
                temp[2].y = j+1;
                temp[2].val = str[i+1][j]-'0';

                temp[3].x = i+2;
                temp[3].y = j+2;
                temp[3].val = str[i+1][j+1]-'0';
                str[i][j] = str[i][j+1] = str[i+1][j] = str[i+1][j+1] = '0';

                sum = temp[0].val + temp[1].val + temp[2].val + temp[3].val;
                sort(&temp[0],&temp[4],compare);
                vec.clear();

                if(sum==3)
                    vec = one(temp[0],temp[1],temp[2],temp[3]);
                if(sum==2)
                    vec = two(temp[0],temp[1],temp[2],temp[3]);
                if(sum==1)
                    vec = three(temp[0],temp[1],temp[2],temp[3]);
                if(sum==4)
                    vec = zero(temp[0],temp[1],temp[2],temp[3]);

                int sz = vec.size();
                for(k=0;k<sz;k++)
                    ans.pb(vec[k]);
            }
        }
        int n = ans.size();
        pf(n/3);
        for(i=0;i<n;i+=3)
            printf("%d %d %d %d %d %d\n",ans[i].x,ans[i].y,ans[i+1].x,ans[i+1].y,ans[i+2].x,ans[i+2].y);
    }

    return 0;
}
