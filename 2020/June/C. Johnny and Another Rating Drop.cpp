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

int dif(string a, string b)
{
    while(a.size()<b.size())
        a = "0"+a;
//    cout<<a<<" "<<b<<endl;
    int cnt = 0,i=0;
    while(i<a.size() && i<b.size())
    {
        if(a[i]!=b[i])
            cnt++;
        i++;
    }
    return cnt;
}

int func(int n)
{
    int sum = 0;
    string str1 = "0";
    string str2 = "1";
    for(int i=1;i<=n;i++)
    {
        str2.clear();
        str2="";
        int x = i;
        while(x!=0)
        {
            if(x%2==0)
                str2 = "0"+str2;
            else
                str2 = "1"+str2;
            x/=2;
        }
        x = dif(str1,str2);
//        printf("%d %d = %d\n",i-1,i,x);
        sum+=x;
        str1.clear();
        str1 = str2;
    }
    return sum;
}

ll go(ll n)
{
    if(n==1LL)
        return 1LL;
    return n + go(n/2LL);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    int i;
//    for(i=1;i<=500;i++)
//    {
//        printf("%d -> %d\n",i,func(i));
//    }
//    for(i=1;i<=500;i++)
//    {
//        printf("%d -> %d\n",i,go(i));
//    }

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",go(n));
    }

    return 0;
}
