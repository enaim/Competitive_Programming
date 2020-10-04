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

int flag[100010];
int ar[100010];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i,a,b,mx=-OO,z,ind=-1,x;
    sf(n);
    if(n==1)
    {
        printf("! 1\n");
        fflush(stdout);
        return 0;
    }
    for(i=1;i<=n-1;i+=2)
    {
        printf("? %d %d\n",i,i+1);
        fflush(stdout);
        sf(a);
        if(a==-1)
            return 0;
        printf("? %d %d\n",i+1,i);
        fflush(stdout);
        sf(b);
        if(b==-1)
            return 0;
        if(a>b)
        {
            ar[i]=a,flag[i]=1;
            if(mx<a)
            {
                mx = a;
                ind = i;
            }
        }
        else
        {
            ar[i+1]=b,flag[i+1]=1;
            if(mx<b)
            {
                mx = b;
                ind = i+1;
            }
        }

    }
    if(n%2==1)
    {
        for(i=1;i<=n-1;i++)
        {
            if(flag[i]==0)
                break;
        }
        printf("? %d %d\n",i,n);
        fflush(stdout);
        sf(a);
        if(a==-1)
            return 0;
        printf("? %d %d\n",n,i);
        fflush(stdout);
        sf(b);
        if(b==-1)
            return 0;
        if(a>b)
        {
            ar[i]=a,flag[i]=1;
            if(mx<a)
            {
                mx = a;
                ind = i;
            }
        }
        else
        {
            ar[n]=b,flag[n]=1;
            if(mx<b)
            {
                mx = b;
                ind = n;
            }
        }
    }
    x = n%mx;

    for(i=1;i<=n;i++)
    {
        if(flag[i]==1)
            continue;
        printf("? %d %d\n",i,ind);
        fflush(stdout);
        sf(a);
        if(a==-1)
            return 0;
        if(a==x)
        {
            ar[i]=n;
            flag[i]=1;
            ind = i;
            break;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(flag[i]==1)
            continue;
        printf("? %d %d\n",i,ind);
        fflush(stdout);
        sf(a);
        if(a==-1)
            return 0;
        ar[i]=a;
        flag[i]=1;
    }
    printf("!");
    for(i=1;i<=n;i++)
        printf(" %d",ar[i]);
    nn;
    fflush(stdout);

    return 0;
}
