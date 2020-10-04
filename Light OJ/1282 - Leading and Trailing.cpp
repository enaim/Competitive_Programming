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

//int dr[]={1,0,-1,0};int dc[]={0,1,0,-1}; //4 Direction
//int dr[]={1,1,0,-1,-1,-1,0,1};int dc[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dc[]={2,1,-1,-2,-2,-1,1,2};int dc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

const double pi = acos(-1.0);
const double eps = 1e-8;

long long BigMod (long long b,long long p,long long M)
{
    long long ans = 1;
    while(p)
    {
        if(p & 1)
            ans = (ans * b) % M;
        b = (b * b) % M;
        p = p >> 1;
    }

    return ans;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n,k,l;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&n,&k);
        double z = log10((double)n)*k;
        z = z-(int)z;
        z = pow(10,z);
        z = z*100;
        l = BigMod(n,k,1000);
        printf("Case %d: %03d %03d\n",ks++,(int)z,l);
    }

    return 0;
}
