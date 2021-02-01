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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,m;
    int tks,ks=1,cnt;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&m);

        cnt = 0;
        int f1=0,f2=0;
        while(n && m)
        {
            if(n<m)
                swap(n,m);
            if(n>m*2 && f1==0 && f2==0)
            {
                if(cnt%2==0)
                    f1 = 1;
                else
                    f2 = 1;
            }
            n = n % m;
            cnt++;
        }
        if(cnt%2==0)
        {
            if(f1==0)
                printf("Rich\n");
            else
                printf("Ari\n");
        }
        else
        {
            if(f2==0)
                printf("Ari\n");
            else
                printf("Rich\n");
        }
    }

    return 0;
}
