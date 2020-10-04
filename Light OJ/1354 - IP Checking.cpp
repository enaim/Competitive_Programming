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

int func(int n)
{
    int a=0,cnt=0;
    while(n!=0)
    {
        a += (n%10) * pow(2,cnt);
        cnt++;
        n/=10;
    }
    return a;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,a,b,c,d,w,x,y,z;
    scanf("%d",&tks);
    while(tks--)
    {
        stringstream ss1,ss2;
        string str1,str2;
        cin>>str1>>str2;
        char s;

        ss1<<str1;
        ss2<<str2;
        ss1>>a>>s>>b>>s>>c>>s>>d;
        ss2>>w>>s>>x>>s>>y>>s>>z;

        w = func(w);
        x = func(x);
        y = func(y);
        z = func(z);

        if(w==a && x==b && y==c && z==d)
            printf("Case %d: Yes\n",ks++);
        else
            printf("Case %d: No\n",ks++);
    }

    return 0;
}
