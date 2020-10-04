#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int len;
    char str[100010];
    while(2==scanf("%d%s",&len,str))
    {
        int i,z,e,r,o,n,one,zero;
        z = e = r = o = n = one = zero = 0;
        for(i=0;i<len;i++)
        {
            if(str[i]=='z')
                z++;
            if(str[i]=='e')
                e++;
            if(str[i]=='r')
                r++;
            if(str[i]=='o')
                o++;
            if(str[i]=='n')
                n++;
        }
        one = min(o,min(n,e));
        o-=one;
        n-=one;
        e-=one;
        zero = min(z,min(e,min(r,o)));
        for(i=0;i<one;i++)
            printf("1 ");
        for(i=0;i<zero;i++)
            printf("0 ");
        printf("\n");
    }

    return 0;
}
