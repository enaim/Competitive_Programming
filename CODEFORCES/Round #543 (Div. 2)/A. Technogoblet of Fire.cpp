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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

int cnt,i,j,x,n,m,k;
int ar[110];
int br[110];
int cr[110];
int sc[110];
int p[110];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(3==scanf("%d%d%d",&n,&m,&k))
    {
        cnt = 0;
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);

        for(i=1;i<=n;i++)
        {
            scanf("%d",&br[i]);
            p[ar[i]]=br[i];
        }

        for(i=1;i<=k;i++)
            scanf("%d",&cr[i]);

        for(i=1;i<=n;i++)
            sc[br[i]]=max(sc[br[i]],ar[i]);

//        for(i=1;i<=m;i++)
//            cout<<i<<" "<<sc[i]<<endl;

        for(i=1;i<=k;i++)
        {
            x = ar[cr[i]];
            x = p[x];
            if(sc[x]!=ar[cr[i]])
                cnt++;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
