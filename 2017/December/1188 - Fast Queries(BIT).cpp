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

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double pi = acos(-1.0);
const double eps = 1e-8;
const int SIZE = 100010;

int ar[SIZE];
int ar1[SIZE];
int prev[SIZE];
int ans[SIZE];
int BIT[SIZE];
int n;
vector<int>vec[SIZE],qnum[SIZE];

void update(int index,int v)
{
    while(index<=n)
    {
        BIT[index] += v;
        index += index &- index;
    }
}

int Query(int index)
{
    int ans = 0;
    while(index>0)
    {
        ans += BIT[index];
        index -= index &- index;
    }
    return ans;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,e,s,x,sz,temp,u,q,z;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        scanf("%d%d",&n,&q);

        memset(BIT,0,sizeof BIT);
        memset(ar,0,sizeof ar);
        memset(prev,0,sizeof prev);
        for(i=1;i<SIZE;i++)
        {
            vec[i].clear();
            qnum[i].clear();
            update(i,0);
        }

        for(i=1;i<=n;i++)
            scanf("%d",&ar1[i]);

        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&s,&e);
            vec[e].pb(s);
            qnum[e].pb(i);
        }

        for(i=1;i<=n;i++)
        {
            temp = ar1[i];
            if(prev[temp] > 0)
            {
                x = prev[temp];
                z = ar[x];
                ar[x] = 0;
                update(x,0-z);
            }

            prev[temp] = i;
            z = ar[i];
            ar[i] = 1;
            update(i,1-z);

            sz = vec[i].size();
            for(j=0;j<sz;j++)
            {
                u = vec[i][j];
                x = qnum[i][j];
                ans[x] = Query(i) - Query(u-1);
            }
        }
        for(i=1;i<=q;i++)
            printf("%d\n",ans[i]);
    }

    return 0;
}
