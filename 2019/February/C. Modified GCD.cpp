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

int ar[5000];
set<int>st;

void Divisors(int n)
{
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                 st.insert(i);
            else
                st.insert(i),st.insert(n/i);
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,m,i,l,r,ans;
    while(2==scanf("%d%d",&n,&m))
    {
        Divisors(__gcd(n,m));
        int cnt=0,q;
        for(auto it:st)
            ar[cnt++]=it;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&l,&r);
            ans = -1;
            for(i=cnt-1;i>=0;i--)
            {
                if(ar[i]<=r && ar[i]>=l)
                {
                    ans = ar[i];
                    break;
                }
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}
