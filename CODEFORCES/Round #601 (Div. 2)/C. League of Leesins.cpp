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

set<int>st[100010];
int flag[100010];
int vis[100010];
int ans[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,x,y,z;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n-2;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            st[x].insert(y);
            st[x].insert(z);

            st[y].insert(x);
            st[y].insert(z);

            st[z].insert(x);
            st[z].insert(y);
            flag[x]++;
            flag[y]++;
            flag[z]++;
        }
        for(i=1;i<=n;i++)
        {
            if(flag[i]==1)
                break;
        }
        ans[1]=i;
        vis[i]=1;
        for(i=2;i<=n;i++)
        {
            if(i==2)
            {
                for(auto it:st[ans[1]])
                {
                    if(flag[it]==2)
                    {
                        ans[i]=it;
                        vis[it]=1;
                        break;
                    }
                }
                continue;
            }
            for(auto it:st[ans[i-2]])
            {
                if(vis[it]==0)
                {
                    ans[i]=it;
                    vis[it]=1;
                    break;
                }
            }
        }
        for(i=1;i<=n;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }

    return 0;
}
