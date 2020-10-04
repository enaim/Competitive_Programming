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

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    string str,a,b,c,ans;
    int n,l,r,i,h;
    scanf("%d",&n);
    cin>>str;

    h = (n+1)/2;
    l = h;
    r = h;
    while(str[l]=='0' && l<n)
        l++;
    while(str[r]=='0' && r>=0)
        r--;
    ans = "99999"+str;
    for(i=l-2;i<min(n,l+10);i++)
    {
        if(str[i]=='0')
            continue;
        if(i-1<=0)
            continue;
        a = str.substr(i,n);
        b = str.substr(0,i);
        c = ADD(a,b);

        if(c.size()<ans.size())
            ans = c;
        else if(c.size()==ans.size() && ans>c)
            ans = c;
    }
    for(i=r+2;i>=max(0,r-10);i--)
    {
        if(str[i+1]=='0')
            continue;
        if(i+1>=n)
            continue;
        a = str.substr(0,i+1);
        b = str.substr(i+1,n);
        c = ADD(a,b);
         if(c.size()<ans.size())
            ans = c;
        else if(c.size()==ans.size() && ans>c)
            ans = c;
    }
    cout<<ans<<endl;

    return 0;
}
