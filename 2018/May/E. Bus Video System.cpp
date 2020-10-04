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

    ll n,w,x,sum=0,l,f;
    while(2==scanf("%lld%lld",&n,&w))
    {
        l = 0;
        f = w;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&x);
            sum+=x;
            l = max(l,-sum);
            f = min(f,w-sum);
        }
        if(l<=f)
            printf("%lld\n",f-l+1);
        else
            printf("0\n");
    }

    return 0;
}
