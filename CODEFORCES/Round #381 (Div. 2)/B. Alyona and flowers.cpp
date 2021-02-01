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

    int ar[110];
    int i,sum,ans,n,q,l,r;
    while(2==scanf("%d%d",&n,&q))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);
        ans = 0;
        while(q--)
        {
            scanf("%d%d",&l,&r);
            sum = 0;
            for(i=l;i<=r;i++)
                sum+=ar[i];
            ans+=max(0,sum);
        }
        printf("%d\n",ans);
    }

    return 0;
}
