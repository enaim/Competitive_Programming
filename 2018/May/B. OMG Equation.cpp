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

int func(int a,int b)
{
    int x = 9*((a+b)*(a+b));
    int y = (a*b)*(a*b);
    return x+(4*a)+(5*b)+y;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,b;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",func(a,b));
    }

    return 0;
}
