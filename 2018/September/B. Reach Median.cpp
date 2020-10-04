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

    ll n,i,mid,s,ind,last,sum;
    ll ar[200010];
    while(2==scanf("%lld%lld",&n,&s))
    {
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i]);
        sort(&ar[0],&ar[n]);

        mid = n/2;
        sum = 0;

        if(s==ar[mid])
            printf("0\n");
        else if(ar[mid]<s)
        {
            for(i=mid;i<n;i++)
            {
                if(ar[i]<s)
                    sum+=abs(ar[i]-s);
            }
            printf("%lld\n",sum);
        }
        else
        {
            for(i=mid;i>=0;i--)
            {
                if(ar[i]>s)
                    sum+=abs(ar[i]-s);
            }
            printf("%lld\n",sum);
        }
    }

    return 0;
}
