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

bool sum(unsigned long long n)
{
    unsigned long long s = 0;
    while(n!=0LL)
    {
        s += (n%10LL);
        n/=10LL;
    }
    if(s%10LL==0)
        return true;
    return false;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output1.txt","w",stdout);

    int tks,ks=1,i;
    unsigned long long x,a,b,c,t;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%llu",&x);
        for(i=0;i<=9;i++)
            if(sum(x*10 + i))
                break;

        printf("%llu\n",x*10+i);
    }

    return 0;
}
