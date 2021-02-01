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
    int n,ar[10010],i,mn,mx;
    while(1==scanf("%d",&n))
    {
        mn = OO;
        mx = -100;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            mn = min(mn,ar[i]);
            mx = max(mx,ar[i]);
        }
        printf("%d\n",abs(mn-mx)-n+1);

    }

    return 0;
}
