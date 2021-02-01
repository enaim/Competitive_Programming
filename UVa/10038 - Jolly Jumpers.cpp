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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,a,b;
    while(1==scanf("%lld",&n))
    {
        set<ll>st;
        ll f = 1,dif;
        for(int i=0;i<n;i++)
        {
            if(i==0)
                scanf("%lld",&a);
            else
                scanf("%lld",&b);
            if(i==0)
                continue;
            st.insert(abs(a-b));
            a = b;
        }
        for(auto it : st)
        {
            if(it==f)
                f++;
        }
        if(n==1)
            printf("Jolly\n");
        else if(f==n)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return 0;
}
