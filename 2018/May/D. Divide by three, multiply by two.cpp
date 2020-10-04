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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll ar[110],n,i,j,k,x,y;
    while(1==scanf("%lld",&n))
    {
        map<ll,int>mp;
        vector<ll>vec;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            ar[i]=x;
            mp[x]++;
        }
        for(i=0;i<n;i++)
        {
            if(ar[i]%2==0)
            {
                x = ar[i]/2;
                if(mp[x]>0)
                    continue;
            }
            x = ar[i]*3;
            if(mp[x]>0)
                continue;
            else
                break;
        }
        vec.pb(ar[i]);
        mp[ar[i]]--;
        for(i=0;i<n*2;i++)
        {
            x = vec[i]*2;
            if(mp[x]>0)
            {
                vec.pb(x);
                mp[x]--;
                continue;
            }
            if(vec[i]%3==0)
            {
                y = vec[i]/3;
                if(mp[y]>0)
                {
                    vec.pb(y);
                    mp[y]--;
                }
            }
        }
        printf("%lld",vec[0]);
        for(i=1;i<n;i++)
            printf(" %lld",vec[i]);
        printf("\n");
    }

    return 0;
}
