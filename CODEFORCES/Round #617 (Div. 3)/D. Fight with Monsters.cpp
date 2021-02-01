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

int ar[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,a,b,k;
    while(4==scanf("%d%d%d%d",&n,&a,&b,&k))
    {
        int cnt = 0,ans = 0,i,z,x;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            x = x%(a+b);
            if(x==0)
                x = a+b;
            if(x<=a)
                ans++;
            else
            {
                x = x-a;
                z = (x+a-1)/a;
                ar[cnt]=z;
                cnt++;
            }
        }
        sort(&ar[0],&ar[cnt]);
        for(i=0;i<cnt;i++)
        {
            if(k>=ar[i])
            {
                k-=ar[i];
                ans++;
            }
            else
                break;
        }
        printf("%d\n",ans);
    }

    return 0;
}
