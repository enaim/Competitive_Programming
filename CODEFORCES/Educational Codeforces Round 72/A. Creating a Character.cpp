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

    int tks,ks=1,mx,a,b,c,mn,x,z;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d",&a,&b,&x);
        if(a+x<=b)
        {
            printf("0\n");
            continue;
        }
        if(a<=b)
        {
            z = b-a+1;
            a+=z;
            x-=z;
        }
        if(b+x<a)
        {
            printf("%d\n",x+1);
            continue;
        }

        z = a - b;
        mn = a + max(0,(x-z)/2);
        mx = a+x;
        printf("%d\n",mx-mn);
    }

    return 0;
}
