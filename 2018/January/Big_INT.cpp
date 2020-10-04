#include <bits/stdc++.h>
using namespace std;


const long long mod = 1000000007;

string MUL(string a,long long b)
{
    long long carry=0,i,l;
    string habijabi="";
    l=a.size()-1;

    for(i=l;i>=0;i--)
    {
        carry += (a[i] - 48) * b;
        habijabi+= ( carry % 10 + 48 );
        carry /= 10;
    }

    while(carry)
    {
        habijabi += ( carry % 10 + 48 );
        carry /= 10;
    }
    reverse(habijabi.begin(),habijabi.end());

    return habijabi;
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
        {
            a += "0";
        }
        reverse(b.begin(),b.end());
    }
    else if(xx<x)
    {
        reverse(b.begin(),b.end());
        for( i =   xx - 1; i < x; i++)
        {
            b += "0";
        }
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

long long MOD(string a)
{
    long long j,k,re,xx,ii;
    int x,i;
    string habijabi = "";
    x = a.size();
    k = 0;
    for(i = 0; i < x; i++)
    {
        k = (k*10) + (a[i] - 48);
        k = k % mod;
    }
    return k;
}

int main()
{
    cout<<MUL("123",10000)<<endl;
    cout<<DIV("120",15)<<endl;
    cout<<ADD("123","10")<<endl;
    cout<<SUB("123","10")<<endl;
    cout<<MOD("10000000023")<<endl;

    return 0;
}
