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

char str[200010],s[10];
int flag[30];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",str);
    for(i=0;i<k;i++)
    {
        scanf("%s",s);
        flag[s[0]-'a']++;
    }
    ll cnt=0LL,sum=0LL;
    for(i=0;i<n;i++)
    {
        if(flag[str[i]-'a']==0)
        {
            sum+=((cnt*(cnt+1LL))/2LL);
            cnt = 0LL;
        }
        else
            cnt++;
    }
    sum+=((cnt*(cnt+1LL))/2LL);
    printf("%lld\n",sum);

    return 0;
}
