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

ll ar[500010],n;

void AllMinus()
{
    ll sum = ar[n-1] ;
    for(int i=n-2;i>=0;i--)
        sum-=ar[i];
    printf("%lld\n",sum);
}

void AllPlus()
{
    if(n==1)
    {
        printf("%d\n",ar[0]);
        return;
    }
    if(n==2)
    {
        printf("%d\n",ar[1]-ar[0]);
        return;
    }

    ll sum = ar[0]-ar[n-1];
    for(int i=2;i<n-1;i++)
        sum-=ar[i];
    sum = ar[1]-sum;
    printf("%lld\n",sum);
}

void Mixed()
{
    ll sum,i,ind,sum1;

    for(i=0;i<n;i++)
    {
        if(ar[i]>=0)
        {
            ind = i;
            break;
        }
    }
    sum1 = 0;
    for(i=ind+1;i<n;i++)
        sum1+=ar[i];
    sum = ar[ind];
    for(i=0;i<ind;i++)
        sum-=ar[i];
    sum+=sum1;

    printf("%lld\n",sum);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,x,mi,pl;
    while(1==scanf("%lld",&n))
    {
        mi = pl = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            if(x<0)
                mi++;
            else
                pl++;
            ar[i]=x;
        }
        sort(&ar[0],&ar[n]);
        if(mi==n)
            AllMinus();
        else if(pl==n)
            AllPlus();
        else
            Mixed();
    }

    return 0;
}
