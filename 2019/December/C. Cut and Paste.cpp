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

char str[1000010];

long long mod = 1e9+7;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll x,i,k,l;
        scanf("%lld%s",&x,str);
        ll sum = strlen(str);
        ll j = sum;
        for(i=0;i<x;i++)
        {
            ll ch = str[i]-'0';
            if(ch==1LL)
                continue;
            if(j<x)
            {
                for(k=0;k<ch-1;k++)
                {
                    for(l=i+1;l<sum;l++)
                    {
                        str[j]=str[l];
                        j++;
                        if(j==x)
                            break;
                    }
                    if(j==x)
                        break;
                }
            }
            sum = ((sum%mod) + ((((sum-(i+1))+mod)%mod)*(ch-1))%mod)%mod;
        }

        printf("%lld\n",sum);
    }

    return 0;
}
