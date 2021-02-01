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

    int i,n,a,b,c,d;
    char str[100];
    while(2==scanf("%d%s",&n,str))
    {
        int mn = OO;
        for(i=0;i<n-3;i++)
        {
            a = min(abs(str[i]-'A'),26-abs(str[i]-'A'));
            b = min(abs(str[i+1]-'C'),26-abs(str[i+1]-'C'));
            c = min(abs(str[i+2]-'T'),26-abs(str[i+2]-'T'));
            d = min(abs(str[i+3]-'G'),26-abs(str[i+3]-'G'));
            mn = min(mn,a+b+c+d);
        }
        cout<<mn<<endl;
    }

    return 0;
}
