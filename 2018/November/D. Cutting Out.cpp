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

int ar[200010],i,j,cnt,k,n,l,r,x,mid;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&k))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            ar[x]++;
        }
        l = 1;
        r = n;
        while(l<=r)
        {
            mid = (l+r)/2;
            cnt = 0;
            for(i=1;i<=2e5;i++)
                cnt += (ar[i]/mid);
            if(cnt>=k)
                l = mid + 1;
            else
                r = mid -1;
        }
        cnt = 0;
        for(i=1;i<=2e5;i++)
        {
            if(cnt==k)
                break;
            for(j=1;j<=ar[i]/r;j++)
            {
                printf("%d ",i);
                cnt++;
                if(cnt==k)
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}
