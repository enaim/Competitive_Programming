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

int ludo[10][10];
int flag[10];
int rnk[10];
int ans;

void Clear()
{
    int i,j;
    for(i=1;i<=6;i++)
        for(j=i;j<=6;j++)
            ludo[i][j]=0;
}

void func()
{
    int cnt = 0,i,j;
    for(i=1;i<=6;i++)
        for(j=i;j<=6;j++)
            if(ludo[i][j])
                cnt++;
    ans = max(ans,cnt);
}
vector<int>vec[100];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,m,i,j,k,u,v,z;
    int ar[7];
    while(2==scanf("%d%d",&n,&m))
    {
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
        }
        if(n<7)
        {
            printf("%d\n",m);
            return 0;
        }
        ans = -OO;
        for(z=1;z<=6;z++)
        {
            for(i=0;i<6;i++)
                ar[i]=i+1;
            ar[i]=z;
            do
            {
                for(i=0;i<7;i++)
                    rnk[i+1]=ar[i];
                for(i=1;i<=6;i++)
                {
                    Clear();
                    rnk[7]=i;
                    for(k=1;k<=6;k++)
                    {
                        u = k;
                        int s = vec[u].size();
                        for(j=0;j<s;j++)
                        {
                            v = vec[u][j];
                            if(rnk[u]>rnk[v])
                                ludo[rnk[v]][rnk[u]]=1;
                            else
                                ludo[rnk[u]][rnk[v]]=1;
                        }
                    }
                    func();
                }

            }while(next_permutation(ar,ar+7));
        }
        cout<<ans<<endl;
    }

    return 0;
}
