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

//const int FLAG_SIZE = 1000100;
//const int PRIME_SIZE = 80000;
//const int M = 1e9+7;
//
//ll flag[FLAG_SIZE/64+10];
//int prime[PRIME_SIZE],ind;
//
//void sieve()//1 indexed
//{
//    long long i,j,k;
//    for(i=3;i<FLAG_SIZE;i+=2)
//         if(!(flag[i/64]&(1LL<<(i%64))))
//                for(j=i*i;j<FLAG_SIZE;j+=2*i)
//                    flag[j/64]|=(1LL<<(j%64));
//    ind = 1;
//    prime[ind++]=2;
//    for (int i=3;i<FLAG_SIZE;i+=2)
//        if(!(flag[i/64]&(1LL<<(i%64))))
//            prime[ind++] = i;
//}
//
//long long BigMod (long long b,long long p)
//{
//    ll ans = 1;
//    while(p)
//    {
//        if(p & 1)
//            ans = (ans * b) % M;
//        b = (b * b) % M;
//        p = p >> 1;
//    }
//
//    return ans;
//}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    sieve();
//    int i,j,n,x,y,res,cnt,c=0;
//    for(i=1;i<=100;i++)
//    {
//        n = i;
//        res = 1;
//        for(j=1;prime[j]<=n/prime[j];j++)
//        {
//            cnt = 0;
//            while(n%prime[j]==0)
//            {
//                n/=prime[j];
//                cnt++;
//            }
//            if(cnt)
//            {
//                x = BigMod(prime[j],cnt+1);
//                y = (x-1)/(prime[j]-1);
//                res*=y;
//            }
//        }
//        if(n!=1)
//        {
//            x = BigMod(n,2);
//            y = (x-1)/(n-1);
//            res*=y;
//        }
//        if(res%2!=0)
//        {
//            c++;
//            printf("%d - > %d\n",i,res);
//        }
//    }
//    cout<<c<<endl;

    int tks,ks=1;
    ll n,ans1,ans2;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        ans1 = sqrt(n);
        ans2 = sqrt(n/2);
        printf("Case %d: %lld\n",ks++,n-ans1-ans2);
    }

    return 0;
}
