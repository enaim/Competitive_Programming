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

int ar[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long mid,i,dif,n,k;
    while(2==scanf("%lld%lld",&n,&k))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        sort(&ar[0],&ar[n]);
        mid = ar[n/2];
        int sz = 1;
        i = n/2;
        while(k!=0)
        {
            if(i==n-1)
            {
                mid+=(k/sz);
                k = 0;
                break;
            }
            dif = ar[i+1]-ar[i];
            if(k>=dif*sz)
            {
                mid+=dif;
                k-=(dif*sz);
            }
            else
            {
                mid+=(k/sz);
                k = 0;
            }
            sz++;
            i++;
        }
        printf("%lld\n",mid);
    }

    return 0;
}
