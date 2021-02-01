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

struct node{
    int x,y;
};

node ar[2010];
int arr[2010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,sum,cnt,a,b,n,m;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        if(m<n || n==2)
        {
            printf("-1\n");
            continue;
        }
        sum = cnt = 0;
        for(i=1;i<=n;i++)
        {
            ar[cnt].x = i;
            sum+=arr[i];
            if(i+1<=n)
                ar[cnt].y = (i+1),sum+=arr[i+1];
            else
                ar[cnt].y = 1,sum+=arr[1];
            cnt++;
        }
        int mn = OO;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                if(mn>arr[i]+arr[j])
                {
                    a = i;
                    b = j;
                    mn = arr[i]+arr[j];
                }
        for(i=n+1;i<=m;i++)
        {
            ar[cnt].x = a;
            ar[cnt].y = b;
            cnt++;
            sum+=mn;
        }
        printf("%d\n",sum);
        for(i=0;i<m;i++)
            printf("%d %d\n",ar[i].x,ar[i].y);
    }

    return 0;
}
