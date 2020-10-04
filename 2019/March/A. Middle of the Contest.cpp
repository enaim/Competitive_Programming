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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int total,ans,h1,h2,m1,m2,i,f,h,m;
    char ch,str1[100],str2[100];
    while(2==scanf("%s%s",str1,str2))
    {
        h1=m1=h2=m2=0;
        f = 1;
        for(i=0;i<strlen(str1);i++)
        {
            if(str1[i]==':')
            {
                f = 0;
                continue;
            }
            if(f)
                h1 = h1*10 + (str1[i]-'0');
            else
                m1 = m1*10 + (str1[i]-'0');
        }
        f = 1;
        for(i=0;i<strlen(str2);i++)
        {
            if(str2[i]==':')
            {
                f = 0;
                continue;
            }
            if(f)
                h2 = h2*10 + (str2[i]-'0');
            else
                m2 = m2*10 + (str2[i]-'0');
        }

        total = (h2*60 + m2) - (h1*60 + m1);
        total/=2;
        ans = (h1*60 + m1) + total;
        h = ans/60;
        m = ans%60;
        if(h<10)
            str1[0]='0',str1[1]=h+'0';
        else
            str1[0]=(h/10)+'0',str1[1]=(h%10)+'0';
        if(m<10)
            str1[3]='0',str1[4]=m+'0';
        else
            str1[3]=(m/10)+'0',str1[4]=(m%10)+'0';

        printf("%s\n",str1);
    }

    return 0;
}
