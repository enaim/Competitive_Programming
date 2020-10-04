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

int br[200010];
int cr[200010];
int flag[200010];
vector<int>vec[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    int n,k,i;
    while(scanf("%d%d",&n,&k)==2)
    {
        int cnt = 0;

        int sum = 0,mn,mx,last,start,dif,val,j,limit;
        for(i=0;i<n;i++)
            scanf("%d",&br[i]);

        sort(&br[0],&br[n]);

        for(i=1;i<=k;i++)
        {
            flag[i]=0;
            scanf("%d",&cr[i]);
        }

        mn = cr[1];
        for(i=2;i<=k;i++)
        {
            mn = min(mn,cr[i]);
            cr[i]=mn;
        }

        for(i=0;i<n;i++)
            flag[br[i]]++;

        last = k;
        for(i=k-1;i>=1;i--)
        {
            if(cr[i+1]==cr[i])
                continue;
            else
            {
                cnt = 0;
                val = cr[i+1];
                start = i+1;
                limit = val-vec[cnt].size();
                for(j=last;j>=start;j--)
                {
                    while(flag[j])
                    {
                        while(limit==0)
                        {
                            cnt++;
                            limit = val - vec[cnt].size();
                        }
                        vec[cnt].pb(j);
                        limit--;
                        flag[j]--;
                    }
                }
                last = i;
            }
        }
        cnt = 0;
        val = cr[1];
        start = 1;
        limit = val-vec[cnt].size();
        for(j=last;j>=start;j--)
        {
            while(flag[j])
            {
                while(limit==0)
                {
                    cnt++;
                    limit = val - vec[cnt].size();
                }
                vec[cnt].pb(j);
                limit--;
                flag[j]--;
            }
        }

        cnt = 0;
        for(i=0;i<200005;i++)
        {
            if(vec[i].size()>0)
                cnt++;
            else
                break;
        }
        printf("%d\n",cnt);
        for(i=0;i<cnt;i++)
        {
            int sz = vec[i].size();
            printf("%d ",sz);
            for(j=0;j<sz;j++)
                printf("%d ",vec[i][j]);
            printf("\n");
        }
    }

    return 0;
}
