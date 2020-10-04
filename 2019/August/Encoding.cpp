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
const int m = 1e9+7;

string ADD(string a,string  b)
{
    int i,j,k,x,xx,cr=0,d,dd,f,ff,sum = 0;
    string habijabi = "";
    x = a.size();
    xx = b.size();
    d = x;
    dd   = x;
    if(d  > xx)  d = xx;
    if(dd < xx) dd  = xx;
    if(xx>x)
    {
        reverse(a.begin(),a.end());
        for( i = x - 1; i < xx; i++)
            a += "0";
        reverse(b.begin(),b.end());
    }
    else if(xx<x)
    {
        reverse(b.begin(),b.end());
        for( i =   xx - 1; i < x; i++)
            b += "0";
        reverse(a.begin(),a.end());
    }
    if(x==xx)
    {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
    }
    for( i = 0 ; i < dd; i++)
    {
        sum = ((a[i]- 48)+(b[i]- 48)+cr);
        habijabi += ( sum % 10 )+ 48;
        cr = sum / 10;
    }
    while(cr)
    {
        habijabi += ( cr % 10 ) + 48;
        cr /= 10;
    }
    reverse(habijabi.begin(),habijabi.end());

    return habijabi;
}

string SUB(string a,string  b)
{
    int i,j,k, kk,x,xx,cr=0,d,dd,f,ff,sum = 0;
    string habijabi = "",habijabi2 = "";
    x = a.size();
    xx = b.size();
    d = x;
    dd   = x;
    if(d  > xx)  d = xx;
    if(dd < xx) dd  = xx;
    if(xx>x)
    {
        reverse(a.begin(),a.end());
        for( i = x - 1; i < xx; i++)
            a += "0";
        reverse(b.begin(),b.end());

        for( i = 0 ; i < xx; i++)
        {
            k = b[i] - 48;
            kk = cr + a[i] - 48;
            cr = 0;
            if(k < kk)
            {
                k += 10;
                cr++;
            }
            sum = k - kk;
            habijabi += sum + 48;
        }
    }
    else if(xx<x)
    {
        reverse(b.begin(),b.end());
        for( i =   xx - 1; i < x; i++)
        {
            b += "0";
        }
        reverse(a.begin(),a.end());

        for( i = 0 ; i < x; i++)
        {
            k = a[i] - 48;
            kk = cr + b[i] - 48;
            cr = 0;
            if(k < kk)
            {
                k += 10;
                cr++;
            }
            sum = k - kk;
            habijabi += sum + 48;
        }
    }
    if(x==xx)
    {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for( i = 0 ; i < x; i++)
        {
            kk = a[i] - 48;
            k = cr + b[i] - 48;
            cr = 0;
            if(k > kk)
            {
                kk += 10;
                cr++;
            }
            sum = kk - k;
            habijabi += sum + 48;

        }
    }
    reverse(habijabi.begin(),habijabi.end());
    x = habijabi.size();
    f = 1;
    for(i = 0;i<x;i++)
    {
        if(f && habijabi[i] == '0')
            continue;;
        habijabi2 += habijabi[i];
        f = 0;
    }
    if(habijabi2 == "")
        habijabi2 = "0";

    return habijabi2;
}

string DIV(string a,long long b)
{
    int i,j,k,x,xx,cr=0,d,dd,f,ff,sum = 0,re=0;
    string habijabi = "";
    x = a.size();
    k = 0;
    d = 0;
    ff = 0;
    for(i = 0; i < x; i++)
    {
        k = (k *10) + ( a[i] - 48);
        if( k <  b  && ff  )
        {
            habijabi += "0";
        }
        if(k >= b)
        {
            re = k/b;
            d = b * re;
            k = k - d;
            habijabi += re + 48;
            ff = 1;
        }
    }
    if(habijabi == "")
        habijabi = "0";

    return habijabi;
}

long long MOD(string a)
{
    long long j,k,re,xx,ii;
    int x,i;
    string habijabi = "";
    x = a.size();
    k = 0LL;
    for(i = 0; i < x; i++)
    {
        k = (k*10) + (a[i] - 48);
        k = k % m;
    }
    return k;
}

long long BigMod (long long b,long long p,long long M)
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

ll mul(ll a,ll b)
{
    return ((a%m)*(b%m))%m;
}

ll add(ll a,ll b)
{
    return ((a%m)+(b%m))%m;
}

ll Equation(ll n)
{
    return mul(mul(n,n+1),BigMod(2,m-2,m));
}

ll Ten[100010];

void TenPower()
{
    Ten[1]=0;
    int cnt = 1,i;
    ll sum,n;
    for(i=2;i<=1e5+10;i++)
    {
        n = BigMod(10,i,m);
        sum = Equation(n);
        Ten[i] = sum - add( mul(495, BigMod(10,cnt,m)), mul(55, BigMod(10,i-2,m)) );
        Ten[i] = (Ten[i]+m)%m;
        cnt+=2;
    }
}


ll ar[100010];
ll solve(string str)
{
    ll n = str.size();
    ll z = n-1,x,i,two;
    ar[n-1] = str[n-1]-'0';
    z = 1;
    for(i=n-2;i>=0;i--)
    {
        ar[i] = add(mul(str[i]-'0',BigMod(10LL,z,m)),ar[i+1]);
        z++;
    }
    z = n-1;
    ll sum = 0;
    ll ans = 0;

    if(n==1)
        return Equation(str[0]-'0');

    for(i=0;i<n-1;i++)
    {
        x = str[i]-'0';
        if(i==n-2)
        {
            x = x*10 + str[i+1]-'0';
            x = x/11;
            x = Equation(x);
            ans+=x;
            break;
        }
        sum = mul(Ten[z],x);

        two = (z-1)+(z-1);
        sum = sum + mul(BigMod(10,two,m),Equation(max(0LL,x-1LL)));
        ans+=sum;
        z--;
        sum = 0LL;
        if(str[i]<=str[i+1] && str[i]!='0')
        {
            two = z;
            ll temp = BigMod(10,z,m);
            if(str[i]<str[i+1])
                sum = mul(mul(x,temp),BigMod(10,two,m));
            else
                sum = mul(mul(x,ar[i+2]+1LL),BigMod(10,two,m));
        }
        ans+=sum;
        ans%=m;
    }
    z = MOD(str);
    z = Equation(z);
    ans = z - ans;
    ans = (ans+m)%m;

    return ans;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    TenPower();
    int tks,ks=1;
    string str1,str2;
    ll ans,ans1,ans2,x;
    scanf("%d",&tks);
    while(tks--)
    {
        cin>>x>>str1;
        cin>>x>>str2;
        str1 = SUB(str1,"1");
        ans1 = solve(str1);
        ans2 = solve(str2);
        ans = ans2-ans1;
        ans = (ans+m)%m;
        printf("%lld\n",ans);
    }

    return 0;
}
