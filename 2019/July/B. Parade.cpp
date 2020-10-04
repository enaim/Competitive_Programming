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

int ar[100010];
int br[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,a,b,n,ans,l,r,x,y;
    while(1==scanf("%d",&n))
    {
        int ind = 0,mx = 0;
        l = r = x = y = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            l+=a;
            r+=b;
            ar[i] = a;
            br[i] = b;
        }
        ans = abs(l-r);
        for(i=0;i<n;i++)
        {
            a = l-ar[i]+br[i];
            b = r-br[i]+ar[i];
            if(ans<abs(a-b))
            {
                ind = i+1;
                ans = abs(a-b);
            }
        }
        printf("%d\n",ind);
    }

    return 0;
}
