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

int ar[110],i,j,n,k,a,b,cnt1,cnt2,mx;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&k))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            if(ar[i]==1)
                cnt1++;
            else
                cnt2++;
        }
        a = cnt1;
        b = cnt2;
        mx = -100000;
        for(i=0;i<n;i++)
        {
            cnt1 = a;
            cnt2 = b;
            for(j=i;j<n;j+=k)
                if(ar[j]==1)
                    cnt1--;
                else
                    cnt2--;
            for(j=i-k;j>=0;j-=k)
                if(ar[j]==1)
                    cnt1--;
                else
                    cnt2--;
            mx = max(mx,abs(cnt1-cnt2));

        }
        printf("%d\n",mx);;
    }

    return 0;
}
