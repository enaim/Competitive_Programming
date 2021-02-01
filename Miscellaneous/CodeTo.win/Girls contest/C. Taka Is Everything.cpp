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

    int tks,ks=1;
    ll ar[4],x;
    while(scanf("%lld%lld%lld%lld",&ar[0],&ar[1],&ar[2],&ar[3])==4)
    {
        scanf("%lld",&x);
        ar[0] = ar[0]*4;
        ar[1] = ar[1]*2;

        sort(&ar[0],&ar[3]);
        if(x==1)
            printf("%lld\n",ar[0]);
        else if(2*ar[0]<ar[3])
            printf("%lld\n",x*ar[0]);
        else
        {
            if(x%2==0)
                printf("%lld\n",(x/2)*ar[3]);
            else
                printf("%lld\n",((x/2)*ar[3])+ar[0]);
        }
    }

    return 0;
}
