#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a1,a2,k1,k2,n,x,y,m,b1,b2;
    while(5==scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n))
    {
        b1= a1;
        b2 = a2;
        m = n;
        if(k1>=k2)
        {
            x = n/k2;
            if(x<=a2)
                n-=(k2*x),a2=x;
            else
                n-=(a2*k2);

            y = n/k1;
            if(y<=a1)
                n-=(k1*y),a1=y;
            else
                n-=(a1*k1);
        }
        else
        {
            x = n/k1;
            if(x<=a1)
                n-=(k1*x),a1=x;
            else
                n-=(a1*k1);

            y = n/k2;
            if(y<=a2)
                n-=(k2*y),a2=y;
            else
                n-=(a2*k2);
        }
        m = max(0,m-(b1*(k1-1))-(b2*(k2-1)));
        if(m>=b1+b2)
            m = b1+b2;
        printf("%d %d\n",m,a1+a2);
    }

    return 0;
}
