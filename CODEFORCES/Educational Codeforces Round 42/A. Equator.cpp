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

    ll ar[200010],n,sum,sum1;
    int i;
    while(1==scanf("%lld",&n))
    {
        sum = 0;
        sum1 = 0;
        for(i=1;i<=n;i++)
        {
            cin>>ar[i];
            sum+=ar[i];
        }
        for(i=1;i<=n;i++)
        {
            sum1+=ar[i];
            if(2*sum1>=sum)
                break;
        }
        printf("%d\n",i);
    }

    return 0;
}
