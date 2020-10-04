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
int m = 1000000007;

int ar[100010];
int br[100010];
int cr[100010];
int dr[100010];

long long BigMod (long long b,long long p)
{
    long long x;

    if( p==0 )
        return 1;

    x = BigMod(b,p/2);
    x = (x*x) % m;

    if(p%2 != 0)
        x=(x*b)%m;

    return x;
}

void initial()
{
    int a = 1;
    ar[1]=1;
    br[1]=2;
    cr[1]=3;
    dr[1]=2;
    for(int i=2;i<=100000;i++)
    {
        if(i%2==0)
        {
            a = a*2 + 1;
            dr[i] = ((dr[i-1]*2) - 2)%m;
        }
        else
        {
            a = a*2 - 1;
            dr[i] = ((dr[i-1]*2) + 2)%m;
        }

        ar[i] = a % m;
        a = a % m;
        br[i]=BigMod(2,i);
        cr[i] = (cr[i-1]*2)%m;
    }

//    for(int i=1;i<=100;i++)
//        printf("%d %d %d %d\n",ar[i],br[i],cr[i],dr[i]);

}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    initial();

    int tks,ks=1,len,sum,cnt,last,i,n;
    scanf("%d",&tks);
    char str[100010];
    while(tks--)
    {
        scanf("%s",str);
        n = strlen(str);
        int x = 0;
        int z = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]!='W')
                x = 1;
            else
                z = 1;
        }

        if(x==0)
        {
            printf("Case %d: %d\n",ks++,cr[n]);
            continue;
        }
        if(z==0)
        {
            printf("Case %d: 0\n",ks++);
            continue;
        }

        sum = 1;
        cnt = 0;
        last = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]=='W')
                cnt++;
            else if(str[i]!='W' && cnt)
            {
                if(last != str[i]-'A' && last)
                    sum = ((sum%m) * (ar[cnt]%m))%m;
                else if(last == str[i]-'A')
                    sum = ((sum%m) * (dr[cnt]%m))%m;
                else if(last==0)
                    sum = ((sum%m) * (br[cnt]%m))%m;
                last = str[i]-'A';
                cnt = 0;
            }
            else if(cnt==0 && str[i]!='W')
                last = str[i]-'A';
        }
        if(cnt)
            sum = (sum%m * br[cnt]%m)%m;

        printf("Case %d: %d\n",ks++,sum);
    }

    return 0;
}
