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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,x,ans,f,i,k,t,j;
    while(2==scanf("%lld%lld",&x,&n))
    {
        f = 0LL;
        if(n%x!=0)
        {
            printf("-1\n");
            continue;
        }
        if(n==x)
        {
            printf("0\n");
            continue;
        }
        for(i=0;i<=30 && !f;i++)
            for(j=0;j<=30 && !f;j++)
            {
                t = x*pow(2,i)*pow(3,j);
                if(t==n)
                {
                    f = 1;
                    break;
                }
            }
        if(f==1)
            printf("%lld\n",i+j-1);
        else
            printf("-1\n");
    }

    return 0;
}
