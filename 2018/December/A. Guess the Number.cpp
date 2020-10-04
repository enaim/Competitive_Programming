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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

    char str[10];
    int l,r,mid;
    l = 1;
    r = 1e6;
    while(l<r)
    {
        mid = (l+r+1)/2;
        printf("%d\n",mid);
        fflush(stdout);

        scanf("%s",str);
        if(str[0]=='<')
            r = mid-1;
        else
            l = mid;
    }
    if(l==r){
        printf("! %d\n",l);
        fflush(stdout);
    }
    else
    {
        printf("! %d\n",mid);
        fflush(stdout);
    }

    return 0;
}
