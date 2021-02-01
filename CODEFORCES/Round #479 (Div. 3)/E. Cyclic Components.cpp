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
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

vector<int>vec[200010],temp;
bool clr[200010];
int cnt,ans,start;

void dfs(int v)
{
    clr[v] = false;
    temp.pb(v);
    for(int i=0;i<vec[v].size();i++)
    {
        int x = vec[v][i];
        if(clr[x]==false)
            continue;
        dfs(x);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,m,i,u,v;
    bool z;
    while(2==scanf("%d%d",&n,&m))
    {
        for(i=0;i<200010;i++)
            vec[i].clear();
        ans = 0;
        memset(clr,true,sizeof clr);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
        }
        for(i=1;i<=n;i++)
        {
            temp.clear();
            if(clr[i])
            {
                dfs(i);
                if(temp.size()<=2)
                    continue;
                z = true;
                for(int j=0;j<temp.size();j++)
                {
                    if(vec[temp[j]].size()!=2)
                        z = false;
                }
                if(z)
                    ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
