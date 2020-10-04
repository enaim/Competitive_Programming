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

    int h,m;
    while(2==scanf("%d%d",&h,&m))
    {
        if(h!=6 && h!=0)
        {
            if(h>6)
                h = 6-(h-6);
            else
                h = 6+6-h;
        }
        if(m!=30 && m!=0)
        {
            if(m>30)
                m = 30-(m-30);
            else
                m = 30+30-m;
        }
        printf("%d %d\n",h,m);
    }

    return 0;
}
