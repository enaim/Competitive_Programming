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

ll m = 1e9+7;

long long BigMod (long long b,long long p)
{
    long long x;

    if( p==0 )
        return 1;

    x = BigMod(b,p/2);
    x = (x*x) % m;

    if(p%2 != 0)
        x=(x*b)%m;

    return x;
}

ll po[100100];
ll ar[100010];
ll br[100010];
char str[100010];
ll i,j,x,y,z,sum,n,q,l,r;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    po[0]=0;
    for(i=1;i<=1e5+10;i++)
    {
        po[i]=BigMod(2,i-1) + po[i-1];
    }

    while(3==scanf("%lld%lld%s",&n,&q,str))
    {
        ar[0]=0;
        br[0]=0;
        for(i=0;i<n;i++)
        {
            ar[i+1]=ar[i];
            br[i+1]=br[i];
            if(str[i]=='0')
                br[i+1]++;
            else
                ar[i+1]++;
        }

        while(q--)
        {
            scanf("%lld%lld",&l,&r);
            ll one = ar[r]-ar[l-1];
            ll zero = br[r]-br[l-1];
            sum = po[one];
            x = (BigMod(2,one)-1);
            y = po[zero];
            z = ((x%m)*(y%m))%m;
            sum+=z;
            sum=sum%m;
            printf("%lld\n",sum);
        }
    }

    return 0;
}
