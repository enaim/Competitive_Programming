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

struct shelf{
    int flag,pos;
};

shelf ar[200010];
int L,R,l,r,id;
char str[10];

void go1()
{
    l = L-ar[id].pos;
    r = ar[id].pos-1 + R;
    printf("%d\n",min(l,r));
}

void go2()
{
    l = ar[id].pos-1+L;
    r = R-ar[id].pos;
    printf("%d\n",min(l,r));
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    L = R = 0;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s%d",str,&id);
        if(str[0]=='L')
        {
            L++;
            ar[id].flag=0;
            ar[id].pos=L;
        }
        if(str[0]=='R')
        {
            R++;
            ar[id].flag=1;
            ar[id].pos=R;
        }
        if(str[0]=='?')
        {
            if(ar[id].flag==0)
                go1();
            else
                go2();
        }
    }

    return 0;
}
