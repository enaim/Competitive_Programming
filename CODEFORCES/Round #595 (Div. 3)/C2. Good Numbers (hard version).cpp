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

unsigned long long p[50];
int flag[50];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    p[0]=1;
    p[1]=3;
    ll i,b;
    for(i=2;i<41;i++)
        p[i]=p[i-1]*3LL;

    ll n,sum,a,temp;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        sum = 0LL;
        memset(flag,0,sizeof flag);
        scanf("%lld",&n);

        a = p[39];
        b = 39;
        temp = n;
        for(i=b-1LL;i>=0LL;i--)
        {
            if(p[i]<=temp)
            {
                temp-=p[i];
                sum+=p[i];
                flag[i]=1;
                if(sum>=n)
                    break;
            }
            else
            {
                b = p[i];
                a = min(a,sum+b);
            }
        }
        i = 0;
        while(sum<n && i<41)
        {
            if(flag[i]==0)
                sum+=n;
            i++;
        }
        if(sum<n)
            printf("%lld\n",a);
        else
            printf("%lld\n",min(a,sum));
    }

    return 0;
}
