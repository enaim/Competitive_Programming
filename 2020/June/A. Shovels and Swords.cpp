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

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int a,b,x,ans,z;
        scanf("%d%d",&a,&b);
        if(a>b)
            swap(a,b);
        x = b/2;
        ans = min(a,x);
        a -= ans;
        b -= (ans*2);
        int mx = ans,l,r,mid;
        l = 0;
        r = ans;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(b+(mid*2)<=(a+mid)/2)
            {
                x = b+(mid*2);
                mx = max(mx,ans-mid+x);
                l = mid+1;
            }
            else
            {
                r = mid - 1;
            }
        }
        mid = r+1;
        if(b+(mid*2)<=(a+mid)/2)
        {
            x = b+(mid*2);
            mx = max(mx,ans-mid+x);
        }
        printf("%d\n",mx);
    }

    return 0;
}
