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

    int ar1[] = {1,2,2,1,0,0};
    int ar2[] = {0,0,1,2,2,1};
    int ar3[] = {2,1,0,0,1,2};
    int n,x;

    while(2==scanf("%d%d",&n,&x))
    {
        n%=6;
        if(n==0)
            n = 6;
        if(ar1[n-1]==x)
            printf("0\n");
        if(ar2[n-1]==x)
            printf("1\n");
        if(ar3[n-1]==x)
            printf("2\n");
    }

    return 0;
}
