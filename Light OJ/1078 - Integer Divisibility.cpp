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

    int tks,ks=1,n,d,cnt;
    scanf("%d",&tks);
    while(tks--)
    {
        cin>>n>>d;
        ll x = d;
        cnt = 1;
        while(x!=0)
        {
            x%=n;
            if(x==0)
                break;
            x = x*10 + d;
            cnt++;
        }
        printf("Case %d: %d\n",ks++,cnt);
    }

    return 0;
}
