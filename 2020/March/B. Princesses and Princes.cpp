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

int flag[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,m,x,j;
        scanf("%d",&n);
        int ans = 0,ind = 0;

        for(i=0;i<n+5;i++)
            flag[i]=0;

        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            int f = 0;
            for(j=0;j<m;j++)
            {
                scanf("%d",&x);
                if(flag[x]==0 && f==0)
                {
                    f = 1;
                    flag[x]=1;
                }
            }
            if(f == 0 && ans == 0)
                ans = i+1;
        }

        for(i=1;i<=n;i++)
            if(flag[i]==0)
            {
                ind = i;
                break;
            }

        if(ans!=0 && ind!=0)
        {
            printf("IMPROVE\n");
            printf("%d %d\n",ans,ind);
        }
        else
            printf("OPTIMAL\n");
    }

    return 0;
}
