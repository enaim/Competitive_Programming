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

ll ar[33000],br[33000],arr[33];
ll i,j,x,l,r,mid,n,w,cnt,temp,len1,len2,sum;

void func()
{
    sort(&arr[0],&arr[n]);
    x = n/2;
    ar[0]=0;
    cnt = 1;
    for(i=0;i<x;i++)
    {
        temp = cnt;
        for(j=0;j<temp;j++)
            ar[cnt++]=ar[j]+arr[i];
    }
    len1 = cnt;
    br[0]=0;
    cnt = 1;
    for(i=x;i<n;i++)
    {
        temp = cnt;
        for(j=0;j<temp;j++)
            br[cnt++]=br[j]+arr[i];
    }
    len2 = cnt;
    sort(&ar[0],&ar[len1]);
    sort(&br[0],&br[len2]);
//    for(i=0;i<len1;i++)
//        printf("%lld ",ar[i]);
//    printf("\n");
//    for(i=0;i<len2;i++)
//        printf("%lld ",br[i]);
//    printf("\n");
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&w);
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        func();
        sum = 0;
        for(i=0;i<len1;i++)
        {
            if(w<ar[i])
                break;
            x = w-ar[i];
            l = 0;
            r = len2-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(br[mid]>x)
                    r = mid-1;
                else
                    l = mid+1;
            }
            sum+=(l-1);
        }
        printf("Case %d: %lld\n",ks++,sum+i);
    }

    return 0;
}
