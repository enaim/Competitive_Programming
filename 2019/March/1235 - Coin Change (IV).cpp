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

ll ar[20010],br[20010],arr[20];
ll n,k,x,i,j,cnt,len1,len2,temp,l,r,mid;

void func()
{
    sort(&arr[0],&arr[n]);
    x = n/2;
    ar[0]=0;
    ar[1]=arr[0];
    ar[2]=arr[0]*2LL;
    cnt = 3;
    for(i=1;i<x;i++)
    {
        temp = cnt;
        for(j=0;j<temp;j++)
        {
            ar[cnt++]=ar[j]+arr[i];
            ar[cnt++]=ar[j]+(arr[i]*2LL);
        }
    }
    len1 = cnt;
    br[0]=0;
    br[1]=arr[x];
    br[2]=arr[x]*2LL;
    cnt = 3;
    for(i=x+1;i<n;i++)
    {
        temp = cnt;
        for(j=0;j<temp;j++)
        {
            br[cnt++]=br[j]+arr[i];
            br[cnt++]=br[j]+(arr[i]*2LL);
        }
    }
    len2 = cnt;
    sort(&ar[0],&ar[len1]);
    sort(&br[0],&br[len2]);
//    for(i=0;i<len1;i++)
//        printf("%d ",ar[i]);
//    printf("\n");
//    for(i=0;i<len2;i++)
//        printf("%d ",br[i]);
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
        scanf("%lld%lld",&n,&k);
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        func();
        int f = 0;
        for(i=0;i<len1;i++)
        {
            if(ar[i]>k)
                break;
            x = k - ar[i];
            l = 0;
            r = len2-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(br[mid]==x)
                {
                    f = 1;
                    break;
                }
                if(br[mid]<x)
                    l = mid+1;
                else
                    r = mid-1;
            }
            if(f)
                break;
        }
        if(f)
            printf("Case %d: Yes\n",ks++);
        else
            printf("Case %d: No\n",ks++);
    }

    return 0;
}
