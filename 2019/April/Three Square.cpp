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

bool go(int a,int b,int c,int d,int e,int f)
{
    if(a==d+e && b+c==b+f && a==b+c)
        return true;
    if(a==b+c+e && a==d && a==f)
        return true;
    return false;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,a,b,c,d,e,f,ar[10],ans;
    for(i=0;i<6;i++)
        scanf("%d",&ar[i]);

    ans = 0;

    a = ar[0];
    b = ar[1];
    c = ar[2];
    d = ar[3];
    e = ar[4];
    f = ar[5];

    if(go(a,b,c,d,e,f))
        ans=1;
    if(go(a,b,c,d,f,e))
        ans=1;
    if(go(a,b,d,c,e,f))
        ans=1;
    if(go(a,b,d,c,f,e))
        ans=1;

    if(go(b,a,c,d,e,f))
        ans=1;
    if(go(b,a,c,d,f,e))
        ans=1;
    if(go(b,a,d,c,e,f))
        ans=1;
    if(go(b,a,d,c,f,e))
        ans=1;

    a = ar[0];
    b = ar[1];
    c = ar[4];
    d = ar[5];
    e = ar[2];
    f = ar[3];

    if(go(a,b,c,d,e,f))
        ans=1;
    if(go(a,b,c,d,f,e))
        ans=1;
    if(go(a,b,d,c,e,f))
        ans=1;
    if(go(a,b,d,c,f,e))
        ans=1;

    if(go(b,a,c,d,e,f))
        ans=1;
    if(go(b,a,c,d,f,e))
        ans=1;
    if(go(b,a,d,c,e,f))
        ans=1;
    if(go(b,a,d,c,f,e))
        ans=1;


    a = ar[2];
    b = ar[3];
    c = ar[0];
    d = ar[1];
    e = ar[4];
    f = ar[5];

    if(go(a,b,c,d,e,f))
        ans=1;
    if(go(a,b,c,d,f,e))
        ans=1;
    if(go(a,b,d,c,e,f))
        ans=1;
    if(go(a,b,d,c,f,e))
        ans=1;

    if(go(b,a,c,d,e,f))
        ans=1;
    if(go(b,a,c,d,f,e))
        ans=1;
    if(go(b,a,d,c,e,f))
        ans=1;
    if(go(b,a,d,c,f,e))
        ans=1;

    a = ar[2];
    b = ar[3];
    c = ar[4];
    d = ar[5];
    e = ar[0];
    f = ar[1];
    if(go(a,b,c,d,e,f))
        ans=1;
    if(go(a,b,c,d,f,e))
        ans=1;
    if(go(a,b,d,c,e,f))
        ans=1;
    if(go(a,b,d,c,f,e))
        ans=1;

    if(go(b,a,c,d,e,f))
        ans=1;
    if(go(b,a,c,d,f,e))
        ans=1;
    if(go(b,a,d,c,e,f))
        ans=1;
    if(go(b,a,d,c,f,e))
        ans=1;


    a = ar[4];
    b = ar[5];
    c = ar[0];
    d = ar[1];
    e = ar[2];
    f = ar[3];
    if(go(a,b,c,d,e,f))
        ans=1;
    if(go(a,b,c,d,f,e))
        ans=1;
    if(go(a,b,d,c,e,f))
        ans=1;
    if(go(a,b,d,c,f,e))
        ans=1;

    if(go(b,a,c,d,e,f))
        ans=1;
    if(go(b,a,c,d,f,e))
        ans=1;
    if(go(b,a,d,c,e,f))
        ans=1;
    if(go(b,a,d,c,f,e))
        ans=1;

    a = ar[4];
    b = ar[5];
    c = ar[2];
    d = ar[3];
    e = ar[0];
    f = ar[1];
    if(go(a,b,c,d,e,f))
        ans=1;
    if(go(a,b,c,d,f,e))
        ans=1;
    if(go(a,b,d,c,e,f))
        ans=1;
    if(go(a,b,d,c,f,e))
        ans=1;

    if(go(b,a,c,d,e,f))
        ans=1;
    if(go(b,a,c,d,f,e))
        ans=1;
    if(go(b,a,d,c,e,f))
        ans=1;
    if(go(b,a,d,c,f,e))
        ans=1;

    if(ans)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
