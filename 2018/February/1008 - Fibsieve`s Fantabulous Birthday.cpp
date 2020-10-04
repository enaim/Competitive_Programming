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

    ll n,x,a,b,del,z;
    int i,tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        x = sqrt(n);
        if(n>x*x)
            x++;
        if(x%2==0)
        {
            z = (x-1)*(x-1);
            del = n-z;
            if(del <= x)
            {
                a = x;
                b = del;
            }
            else
            {
                b = x;
                a = x-(del-x);
            }
        }
        else
        {
            z = (x-1)*(x-1);
            del = n-z;
            if(del<x)
            {
                b = x;
                a = del;
            }
            else
            {
                a = x;
                b = x-(del-x);
            }
        }

        printf("Case %d: %lld %lld\n",ks++,b,a);
    }

    return 0;
}
