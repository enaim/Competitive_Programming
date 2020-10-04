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

int hh,ww,h,w;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    char str[5];
    scanf("%d",&tks);
    hh = ww = -1;
    while(tks--)
    {
        scanf("%s%d%d",str,&h,&w);
        if(str[0]=='+')
        {
            if(h>w)
                swap(h,w);
            hh = max(hh,h);
            ww = max(ww,w);
        }
        else
        {
            if(h>w)
                swap(h,w);
            if(hh<=h && ww<=w)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
