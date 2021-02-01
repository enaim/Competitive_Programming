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

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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
    int x,y,in;
};
node dis[210];
int flag[210];
int ar[210];

bool compare(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,n,k;
        memset(flag,0,sizeof flag);
        memset(ar,0,sizeof ar);
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&dis[i].x,&dis[i].y);
            dis[i].in = i;
            for(j=dis[i].x;j<=dis[i].y;j++)
                ar[j]++;
        }
        sort(&dis[0],&dis[n],compare);
        int bad=0;
        vector<int>vec;
        while(bad!=-1)
        {
            bad = -1;
            for(i=1;i<=200;i++)
                if(ar[i]>k)
                {
                    bad = i;
                    break;
                }
            if(bad==-1)
                break;
            int mx = -1;
            int ind = -1;
            for(i=0;i<n;i++)
            {
                if(dis[i].x>bad)
                    break;
                if(mx<=dis[i].y && flag[i]==0)
                {
                    mx = dis[i].y;
                    ind = i;
                }
            }
            vec.pb(dis[ind].in);
            flag[ind]=1;
            for(j=dis[ind].x;j<=dis[ind].y;j++)
                ar[j]--;
        }
        int sz = vec.size();
        cout<<sz<<endl;
        for(i=0;i<sz;i++)
            printf("%d ",vec[i]+1);
        printf("\n");

    return 0;
}
