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
    int i,cnt,n;
    ll ans1,ans2,x,y,one,zero;
    char str[300010],s[300010];
    while(4==scanf("%d%lld%lld%s",&n,&x,&y,s))
    {
        cnt = 1;
        for(i=0;i<n;i++)
        {
            if(i==0)
                str[0]=s[0];
            else if(str[cnt-1]!=s[i])
                str[cnt++] = s[i];
        }
        one = zero = 0;
        for(i=0;i<cnt;i++)
        {
            if(str[i]=='1')
                one++;
            else
                zero++;
        }
        if(str[0]=='1')
            one--;
        if(str[cnt-1]=='1' && cnt >1)
            one--;
        ans1 = ans2 = 0;
        if(zero)
        {
            ans1 = (one*x) + y;
            ans2 = (y*zero);
        }

        printf("%lld\n",min(ans1,ans2));
    }

    return 0;
}
