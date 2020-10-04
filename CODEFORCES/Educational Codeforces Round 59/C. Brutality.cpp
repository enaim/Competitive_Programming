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

vector<ll>vec;
char str[200010];
int ar[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,k,sum,i,j,sz;
    while(2==scanf("%lld%lld",&n,&k))
    {
        sum = 0LL;
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i]);
        scanf("%s",str);
        vec.pb(ar[0]);
        sz = 1LL;
        for(i=1;i<n;i++)
        {
            if(str[i]==str[i-1])
            {
                vec.pb(ar[i]);
                sz++;
            }
            else
            {
                sort(vec.rbegin(),vec.rend());
                for(j=0;j<sz && j<k;j++)
                    sum+=vec[j];
                vec.clear();
                sz = 1;
                vec.pb(ar[i]);
            }
        }
        sort(vec.rbegin(),vec.rend());
        for(j=0;j<sz && j<k;j++)
            sum+=vec[j];
        vec.clear();

        printf("%lld\n",sum);
    }

    return 0;
}
