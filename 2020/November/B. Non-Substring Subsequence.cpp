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

char str[110];
char temp[110];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,n,q,l,r,cnt=0,cnt1=0,zero=0,one=0,z,o,last;
        sf2(n,q);
        ssf(str);
        for(i=0;i<n;i++)
            if(str[i]=='0')
                zero++;
            else
                one++;
        while(q--)
        {
            sf2(l,r);
            cnt = 0;
            for(i=l-1;i<r;i++)
                temp[cnt++]=str[i];
            temp[cnt]='\0';
            i = 0;
            j = 0;
            int f = 0,zz=0,oo=0;
            z = o = 0;
            while(i<n && j<cnt)
            {
                if(str[i]==temp[j])
                    j++,f=1;
                if(str[i]=='0' && f==1)
                {
                    z++;
                    last = 0;
                }
                else if(f==1)
                {
                    o++;
                    last = 1;
                }
                if(str[i]=='0' && f==0)
                {
                    zz++;
                    last = 0;
                }
                else if(f==0)
                {
                    oo++;
                    last = 1;
                }
                i++;
            }
            if(cnt<2)
                puts("NO");
            else if(j==cnt && o+z!=cnt && f==1)
                puts("YES");
            else if(j==cnt && o+z==cnt && last == 0 && z!=zero-zz && f==1)
                puts("YES");
            else if(j==cnt && o+z==cnt && last == 1 && o!=one-oo && f==1)
                puts("YES");
            else
                puts("NO");
        }

    }

    return 0;
}
