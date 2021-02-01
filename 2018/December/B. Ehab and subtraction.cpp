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

ll ar[100010],n,k,i;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%lld%lld",&n,&k))
    {
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i]);
        sort(&ar[0],&ar[n]);
        int cnt = 0;
        ll sum = 0;
        for(i=0;i<n;i++)
        {
            ll x = ar[i]-sum;
            if(x==0)
                continue;
            sum+=x;
            printf("%d\n",x);
            cnt++;
            if(cnt==k)
                break;
        }
        for(int j=cnt+1;j<=k;j++)
            printf("0\n");
    }

    return 0;
}
