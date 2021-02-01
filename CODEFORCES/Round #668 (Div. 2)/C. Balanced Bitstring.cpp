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

char str[300010];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,k,flag,one,zero,mark,j,need;
        sf2(n,k);
        ssf(str);
        if(k%2!=0)
        {
            puts("NO");
            continue;
        }
        for(i=0;i<k;i++)
        {
            if(str[i]=='?')
            {
                j = i+k;
                while(j<n)
                {
                    if(str[j]=='?')
                    {
                        j+=k;
                        continue;
                    }
                    else
                    {
                        str[i]=str[j];
                        break;
                    }
                }
            }
        }
        one = zero = mark = 0;
        for(i=0;i<k;i++)
        {
            if(str[i]=='0')
                zero++;
            else if(str[i]=='1')
                one++;
            else
                mark++;
        }
        need = k/2;
        if(zero > need || one>need)
        {
            puts("NO");
            continue;
        }
        for(i=0;i<k;i++)
        {
            if(mark==0)
                break;
            if(str[i]=='?')
            {
                if(zero<need)
                {
                    zero++;
                    mark--;
                    str[i]='0';
                }
                else
                {
                    mark--;
                    str[i]='1';
                }
            }
        }

        flag = 0;
        for(i=0;i<n-k;i++)
        {
            if(str[i+k]=='?')
                str[i+k]=str[i];
            else if(str[i]==str[i+k])
                continue;
            else
                break;
        }
        if(i==n-k)
            flag = 1;
        if(flag)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
