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
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

    int tks,ks=1,m=1e7+7,i,j;
    ll ar[10010],n,sum;
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=0;i<6;i++)
            scanf("%lld",&ar[i]);
        scanf("%lld",&n);
        if(n<=5)
        {
            printf("Case %d: %lld\n",ks++,ar[n]%m);
            continue;
        }
        for(i=6;i<=n;i++)
        {
            sum = 0;
            for(j=i-1;j>=i-6;j--)
                sum = ((sum%m)+(ar[j]%m))%m;
            ar[i] = sum;
            if(i==n)
                break;
        }
        printf("Case %d: %lld\n",ks++,ar[n]%m);
    }

    return 0;
}
