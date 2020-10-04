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

int ar[400010];
int br[400010];
int flag[400100];
vector<int>vec[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n;
    while(1==scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&br[i]);
        for(i=1;i<=n;i++)
            br[i+n]=br[i];
        for(i=1;i<=2*n;i++)
            vec[br[i]].pb(i);
        for(i=1;i<=n;i++)
        {
            int x = ar[i];
            for(j=0;j<=1;j++)
            {
                if(vec[x][j]-(i-1)>=1 && vec[x][j]+(n-i)<=2*n)
                    flag[vec[x][j]-(i-1)]++;
            }
        }
        int mx = 0;
        for(i=0;i<=2*n+5;i++)
            mx = max(flag[i],mx);
        cout<<mx<<endl;
    }

    return 0;
}
