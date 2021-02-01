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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

struct node{
    int v,ind;
};

node ar[200010];
vector<int>v1,v2,v3;

bool compare(node a,node b)
{
    return a.v<b.v;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,x,t;

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i].v);
            ar[i].ind = i;
        }
        sort(&ar[0],&ar[n],compare);
        if(n==2)
        {
            printf("1\n");
            continue;
        }
        for(i=2;i<n;i++)
            v1.pb(ar[i].v-ar[1].v);
        for(i=2;i<n;i++)
            v2.pb(ar[i].v-ar[0].v);
        for(i=1;i<n;i++)
            v3.pb(ar[i].v-ar[0].v);

        int cnt = 2;
        x = ar[2].v-ar[1].v;
        for(i=1;i<n-2;i++)
        {
            if(v1[i]==(cnt*x))
                cnt++;
        }
        if(cnt==n-1)
        {
            printf("%d\n",ar[0].ind+1);
            continue;
        }

        cnt = 2;
        x = ar[2].v-ar[0].v;
        for(i=1;i<n-2;i++)
        {
            if(v2[i]==(cnt*x))
                cnt++;
        }
        if(cnt==n-1)
        {
            printf("%d\n",ar[1].ind+1);
            continue;
        }

        cnt = 2;
        x = ar[1].v-ar[0].v;
        for(i=1;i<n-1;i++)
        {
            if(v3[i]==(cnt*x))
                cnt++;
            else
                t = ar[i+1].ind;
        }
        if(cnt==n-1)
        {
            printf("%d\n",t+1);
            continue;
        }
        printf("-1\n");
    }

    return 0;
}
