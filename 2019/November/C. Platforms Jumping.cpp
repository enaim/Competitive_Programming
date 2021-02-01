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

int ar[10010];
int start[10010];
int c[10010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n,m,d,x,last;
    while(3==scanf("%d%d%d",&n,&m,&d))
    {
        for(i=1;i<=n;i++)
            ar[i]=0;
        for(i=1;i<=m;i++)
            scanf("%d",&c[i]);
        j = 1;
        for(i=1;i<=m;i++)
        {
            x = c[i];
            start[i]=j;
            while(x)
            {
                ar[j]=i;
                j++;
                x--;
            }
        }
        last = j-1;
        for(j=1;j<=m;j++)
        {
            x = d-1;
            if(x+last<n+1)
            {
                for(i=n;i>=start[j]+x;i--)
                    ar[i]=ar[i-x];
                for(i=start[j];i<start[j]+x;i++)
                    ar[i]=0;
            }
            else if(last<n+1)
            {
                x = n-last;
                for(i=n;i>=start[j]+x;i--)
                    ar[i]=ar[i-x];
                for(i=start[j];i<start[j]+x;i++)
                    ar[i]=0;
            }
            for(i=n;i>=1;i--)
                start[ar[i]]=i;
            last = min(n,start[m]+c[m]-1);
        }
        if(last+d<n+1)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(i=1;i<=n;i++)
            printf("%d ",ar[i]);
    }

    return 0;
}
