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
const ll M = 1e9+7;

long long BigMod (long long b,long long p)
{
    long long ans = 1;
    while(p)
    {
        if(p & 1)
            ans = (ans * b) % M;
        b = (b * b) % M;
        p = p >> 1;
    }

    return ans;
}


char str[100010];
ll fib[100010];
vector<int>vec1,vec;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i;
    while(1==scanf("%s",str))
    {

        fib[0]=0;
        fib[1]=1;
        fib[2]=1;

        for(i=3;i<=100005;i++)
            fib[i] = ((fib[i-1]%M)+(fib[i-2]%M))%M;
        vec.clear();
        vec1.clear();
        int cnt = 0;
        int n = strlen(str);
        for(i=0;i<n;i++)
        {
            if(cnt && str[i]=='u')
            {
                cnt++;
            }
            else if(str[i]=='u')
            {
                cnt = 1;
            }
            else
            {
                if(cnt>1)
                    vec.pb(cnt);
                cnt = 0;
            }
        }
        if(cnt>1)
            vec.pb(cnt);

        cnt = 0;
        for(i=0;i<n;i++)
        {
            if(cnt && str[i]=='n')
            {
                cnt++;
            }
            else if(str[i]=='n')
            {
                cnt = 1;
            }
            else
            {
                if(cnt>1)
                    vec1.pb(cnt);
                cnt = 0;
            }
        }
        if(cnt>1)
            vec1.pb(cnt);
        ll ans = 1;
        int sz = vec.size();
        for(i=0;i<sz;i++)
        {
            ans*=fib[vec[i]+1];
            ans%=M;
        }
        sz = vec1.size();
        for(i=0;i<sz;i++)
        {
            ans*=fib[vec1[i]+1];
            ans%=M;
        }
        for(i=0;i<n;i++)
            if(str[i]=='m' || str[i]=='w')
                ans = 0;
        printf("%lld\n",ans);
    }

    return 0;
}
