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

    int tks,ks=1,len;
    ll n;
    char str[1000];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s%lld",str,&n);
        len = strlen(str);
        ll x = 0;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='-')
                continue;
            x = x*10 + str[i]-'0';
            x = x%n;
        }
        if(x==0)
            printf("Case %d: divisible\n",ks++);
        else
            printf("Case %d: not divisible\n",ks++);
    }

    return 0;
}
