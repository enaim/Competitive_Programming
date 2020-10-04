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

struct node{
    ll x,y;
};
node ar[10];

ll dis(node a,node b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,sum;
    ll ab[10];
    while(2==scanf("%lld%lld",&ar[0].x,&ar[0].y))
    {
        for(i=1;i<=3;i++)
            scanf("%lld%lld",&ar[i].x,&ar[i].y);
        ab[0]=1;
        ab[1]=2;
        ab[2]=3;
        ll mn = 1e18;
        do{
            sum = 0;
            sum += dis(ar[0],ar[ab[0]]);
            sum += dis(ar[ab[0]],ar[ab[1]]);
            sum += dis(ar[ab[1]],ar[ab[2]]);
            sum += dis(ar[ab[2]],ar[0]);
            mn = min(mn,sum);

        }while(next_permutation(ab,ab+3));

        printf("%lld\n",mn);
    }

    return 0;
}
