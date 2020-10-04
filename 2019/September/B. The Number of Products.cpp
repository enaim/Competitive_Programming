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

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long i,n,ans1,ans2,pos,neg;
    int ar[200010];
    while(1==scanf("%lld",&n))
    {
        pos = neg = ans1 = ans2 = 0;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<n;i++)
        {
            if(ar[i]<0)
            {
                ans2+=neg;
                ans1+=pos;
                if(i+1<n && ar[i+1]<0)
                {
                    neg++;
                    ans2++;
                    swap(pos,neg);
                }
                else
                {
                    neg++;
                    ans2++;
                }
            }
            else
            {
                ans2+=neg;
                ans1+=pos;
                if(i+1<n && ar[i+1]<0)
                {
                    pos++;
                    ans1++;
                    swap(pos,neg);
                }
                else
                {
                    pos++;
                    ans1++;
                }
            }
        }
        printf("%lld %lld\n",ans2,ans1);
    }

    return 0;
}
