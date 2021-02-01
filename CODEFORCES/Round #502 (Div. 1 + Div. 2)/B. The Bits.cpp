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

    ll n,cnt,cnt1,i,zero,one,ans;
    char str[100010],str1[100010];
    while(1==scanf("%lld",&n))
    {
        cnt = cnt1 = zero = one = 0;
        scanf("%s%s",str,str1);
        for(i=0;i<n;i++)
        {
            if(str[i]=='1')
                cnt++;
            else
                cnt1++;
        }
        for(i=0;i<n;i++)
        {
            if(str1[i]=='0' && str[i]=='1')
                one++;
            else if(str1[i]=='0' && str[i]=='0')
                zero++;
        }
        ans = cnt*zero + (one*(cnt1-zero));

        printf("%lld\n",ans);
    }

    return 0;
}
