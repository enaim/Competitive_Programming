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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

ll ar[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,n,cnt1,cnt2,z,sum,x;

    while(1==scanf("%lld",&n))
    {
        sum = cnt1=cnt2=z=0LL;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            if(x>0)
            {
                sum+=(x-1);
                ar[i] = 1;
                cnt1++;
            }
            else if(x<0)
            {
                sum+=(abs(x)-1);
                ar[i] = -1;
                cnt2++;
            }
            else
                ar[i]=0,z++;
        }
        if(cnt2%2LL!=0LL)
        {
            if(z)
            {
                sum+=z;
            }
            else
            {
                sum+=2;
            }
        }
        else
            sum+=z;
        printf("%lld\n",sum);
    }

    return 0;
}
