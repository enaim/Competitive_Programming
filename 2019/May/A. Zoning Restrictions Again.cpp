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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[60],n,h,m,i,j,l,r,x,sum;
    while(3==scanf("%d%d%d",&n,&h,&m))
    {
        for(i=1;i<=n;i++)
            ar[i]=h;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&l,&r,&x);
            for(j=l;j<=r;j++)
                ar[j]=min(ar[j],x);
        }
        sum = 0;
        for(i=1;i<=n;i++)
            sum+=(ar[i]*ar[i]);
        printf("%d\n",sum);
    }

    return 0;
}
