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

    int n,k;

    while(2==scanf("%d%d",&n,&k))
    {
        int r,g,b,sum=0;
        r = 2*n;
        g = 5*n;
        b = 8*n;
        if(r%k==0)
            sum+=(r/k);
        else
            sum+=((r/k) + 1);
        if(g%k==0)
            sum+=(g/k);
        else
            sum+=((g/k) + 1);
        if(b%k==0)
            sum+=(b/k);
        else
            sum+=((b/k) + 1);
        printf("%d\n",sum);
    }

    return 0;
}
