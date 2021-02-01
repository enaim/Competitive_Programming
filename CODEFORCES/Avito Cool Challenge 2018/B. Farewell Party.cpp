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

struct node
{
    int v,ind;
};
node ar[100010];

bool compare(node x,node y)
{
    if(x.v==y.v)
        return x.ind<y.ind;
    return x.v<y.v;
}

int br[100010],clr[100010],ff[100010],cnt[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i,j,x,c;
    while(1==scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            ar[i].v = x;
            ar[i].ind = i;
            cnt[x]++;
        }
        if(cnt[0]==n)
        {
            printf("Possible\n");
            for(i=1;i<=n;i++)
                printf("1 ");
            printf("\n");
            continue;
        }
        if(cnt[0])
        {
            printf("Impossible\n");
            continue;
        }
        sort(&ar[1],&ar[n+1],compare);
        int k = 1;
        int r = 0;
        int flag = 0;
        for(i=1;i<=n;i++)
        {
            x = n-ar[i].v;
            if(clr[i]!=0)
            {
                if(n-ar[i].v!=ff[clr[i]])
                {
                    flag = 1;
                    break;
                }
            }
            else
            {
                for(j=k;j<=k+(n-ar[i].v)-1&& j<=n;j++)
                {
                    clr[j]=r+1;
                    ff[r+1]++;
                }
                if(j-1!=k+(n-ar[i].v)-1)
                {
                    flag = 1;
                    break;
                }
                k = j;
                r++;
            }
        }

        if(flag)
            printf("Impossible\n");
        else
        {
            printf("Possible\n");
            for(i=1;i<=n;i++)
            {
                br[ar[i].ind]=clr[i];
            }
            for(i=1;i<=n;i++)
                printf("%d ",br[i]);
            printf("\n");
        }
    }

    return 0;
}
