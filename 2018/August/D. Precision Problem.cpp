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

    int tks,ks=1,;
    double n;
    int d;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf%d",&n,&d);
        if(d==0)
            printf("%.0lf\n",n);
        if(d==1)
            printf("%.1lf\n",n);
        if(d==2)
            printf("%.2lf\n",n);
        if(d==3)
            printf("%.3lf\n",n);
        if(d==4)
            printf("%.4lf\n",n);
        if(d==5)
            printf("%.5lf\n",n);
        if(d==6)
            printf("%.6lf\n",n);
    }

    return 0;
}
