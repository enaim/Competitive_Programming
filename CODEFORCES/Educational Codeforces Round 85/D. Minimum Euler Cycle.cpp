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

vector<ll>vec;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll i,j,ind,last,sum,n,l,r;
        scanf("%lld%lld%lld",&n,&l,&r);
        sum = 0LL;
        last = 0LL;
        ind = 0;
        for(i=1;i<n;i++)
        {
            sum = sum + ((n-i)*2LL);
            if(l<=sum)
                break;
            last = sum;
            ind = i;
        }
        ll cnt = last;
        ind++;
        i = ind;
        j = ind;
        vec.clear();
        while(cnt<r && cnt<n*(n-1))
        {
            cnt++;
            if(cnt>=l && cnt<=r)
                vec.pb(i);
            cnt++;
            if(j<n)
                j++;
            if(cnt>=l && cnt<=r)
                vec.pb(j);

            if(j==n)
            {
                i++;
                j = i;
            }
        }
        if(cnt<r)
            vec.pb(1LL);
        ll sz = vec.size();
        for(i=0;i<sz;i++)
            printf("%lld ",vec[i]);
        cout<<endl;
    }

    return 0;
}
