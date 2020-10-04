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

    int a,b,x1,x2,y1,y2;
    while(4==scanf("%d%d%d%d",&x1,&y1,&x2,&y2))
    {
        a = x1*x1 + y1*y1;
        b = x2*x2 + y2*y2;
        if(a<b)
            printf("Russo\n");
        else if(a>b)
            printf("Wil\n");
        else
            printf("Empate\n");
    }

    return 0;
}
