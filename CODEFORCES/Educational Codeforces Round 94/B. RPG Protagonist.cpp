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

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll p,f,sord,war,s,w,i,temp1,temp2,cnt1,cnt2,cnt,mx=0LL,x;
        sl2(p,f);
        if(p>f)
            swap(p,f);
        sl2(sord,war);
        sl2(s,w);
        if(s>w)
        {
            swap(s,w);
            swap(sord,war);
        }
        for(i=0;i<=sord;i++)
        {
            temp1 = p;
            temp2 = f;
            cnt1 = sord;
            cnt2 = war;
            cnt = 0;
            if(temp1>=i*s)
            {
                temp1 -= (i*s);
                cnt += i;
                cnt1 -= i;
            }

            if(temp1>=w)
            {
                x = temp1/w;
                if(x>=cnt2)
                {
                    cnt += cnt2;
                    temp1 -= (cnt2*w);
                    cnt2 = 0;
                }
                else
                {
                    cnt += x;
                    temp1 -= (x*w);
                    cnt2 -= x;
                }
            }

            if(temp2>=s)
            {
                x = temp2/s;
                if(x>=cnt1)
                {
                    cnt += cnt1;
                    temp2 -= (s*cnt1);
                    cnt1 = 0;
                }
                else
                {
                    cnt += x;
                    temp2 -= (s*x);
                    cnt1 -= x;
                }
            }

            if(temp2>=w)
            {
                x = temp2/w;
                if(x>=cnt2)
                {
                    cnt += cnt2;
                    temp2 -= (cnt2*w);
                    cnt2 = 0;
                }
                else
                {
                    cnt += x;
                    temp2 -= (x*w);
                    cnt2 -= x;
                }
            }
            mx = max(cnt,mx);
        }
        pl(mx);
    }

    return 0;
}
