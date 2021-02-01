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

    int a,d;
    int ar[4];
    while(4==scanf("%d%d%d%d",&ar[0],&ar[1],&ar[2],&d))
    {
        sort(&ar[0],&ar[3]);
        a =  0;
        if(abs(ar[0]-ar[1])<d)
            a += d-abs(ar[0]-ar[1]);

        if(abs(ar[1]-ar[2])<d)
            a += d-abs(ar[1]-ar[2]);

        printf("%d\n",a);
    }

    return 0;
}
