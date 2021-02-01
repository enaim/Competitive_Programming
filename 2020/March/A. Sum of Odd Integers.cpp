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

ll ar[10000010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i;
    ar[0]=0;
    ar[1]=1;
    for(i=2;i<1e7+5;i++)
        ar[i] = ar[i-1]+ ((i-1)*2LL) + 1LL;

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll n,k;
        scanf("%lld%lld",&n,&k);
        if(k==1LL)
        {
            if(n%2LL==1LL)
            {
                printf("YES\n");
                continue;
            }
            else
            {
                printf("NO\n");
                continue;
            }
        }
        ll rem = n-ar[k-1];
        if(rem>0LL && rem%2LL==1LL && rem>((k-2)*2LL)+1LL)
        {
            printf("YES\n");
            continue;
        }
        else
        {
            printf("NO\n");
            continue;
        }
    }

    return 0;
}
