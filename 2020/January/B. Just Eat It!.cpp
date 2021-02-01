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

ll ar[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,i,sum1,sum;
    int tks;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        sum1 = sum = 0LL;
        int flag = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
            sum+=ar[i];
        }
        sum1 = 0LL;
        for(i=0;i<n-1;i++)
        {
            sum1+=ar[i];
            if(sum1>=sum)
            {
                flag = 1;
                break;
            }
            if(sum1<0)
                sum1 = 0LL;
        }
        sum1 = 0LL;
        for(i=1;i<n;i++)
        {
            sum1+=ar[i];
            if(sum1>=sum)
            {
                flag = 1;
                break;
            }
            if(sum1<0)
                sum1 = 0LL;
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}#include <map>
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

ll ar[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,i,sum1,sum;
    int tks;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        sum1 = sum = 0LL;
        int flag = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
            sum+=ar[i];
        }
        sum1 = 0LL;
        for(i=0;i<n-1;i++)
        {
            sum1+=ar[i];
            if(sum1>=sum)
            {
                flag = 1;
                break;
            }
            if(sum1<0)
                sum1 = 0LL;
        }
        sum1 = 0LL;
        for(i=1;i<n;i++)
        {
            sum1+=ar[i];
            if(sum1>=sum)
            {
                flag = 1;
                break;
            }
            if(sum1<0)
                sum1 = 0LL;
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
