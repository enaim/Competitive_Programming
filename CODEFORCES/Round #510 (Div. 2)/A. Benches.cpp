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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[10010],n,m,x,sum,i,r,mx,mn;
    while(2==scanf("%d%d",&n,&m))
    {
        sum = 0;
        mn = OO;
        mx = -1000000;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            sum+=x;
            mx =max(mx,x);
            mn =min(mn,x);
        }
        if((sum+m)%n==0)
            r = (sum+m)/n;
        else
            r = ((sum+m)/n) + 1;
        printf("%d %d\n",max(mx,r),mx+m);
    }

    return 0;
}
