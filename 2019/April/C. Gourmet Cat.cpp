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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

map<ll,ll>mp;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    mp[0]=2;
    mp[1]=1;
    mp[2]=1;
    mp[3]=2;
    mp[4]=3;
    mp[5]=1;
    mp[6]=3;


    ll flag[4],temp[4],mx,mn,cnt,i,x,j;

    while(3==scanf("%lld%lld%lld",&flag[1],&flag[2],&flag[3]))
    {
        mn = min(flag[1]/3,min(flag[2]/2,flag[3]/2));
        flag[1]-=(mn*3);
        flag[2]-=(mn*2);
        flag[3]-=(mn*2);
        mx = 0;
        for(i=0;i<7;i++)
        {
            for(j=1;j<=3;j++)
                temp[j]=flag[j];

            cnt = 0;
            x = i;
            while(true)
            {
                if(temp[mp[x%7]]>0)
                    temp[mp[x%7]]--;
                else
                    break;
                x++;
                cnt++;
            }
            mx = max(mx,cnt);
        }
        printf("%lld\n", (mn*7LL) + mx);
    }

    return 0;
}
