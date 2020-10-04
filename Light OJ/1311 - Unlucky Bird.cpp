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

    int tks,ks=1;
    double v1,v2,v3,a1,a2,t,t1,t2,s1,s2;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
        s1 = (v1*v1)/(2*a1);
        s2 = (v2*v2)/(2*a2);
        t1 = v1/a1;
        t2 = v2/a2;
        t = max(t1,t2);
        printf("Case %d: %.10lf %.10lf\n",ks++,s1+s2,t*v3);
    }

    return 0;
}
