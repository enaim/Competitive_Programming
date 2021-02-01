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

const int FLAG_SIZE = 1001000;
const int PRIME_SIZE = 80000;

bool flag[FLAG_SIZE];
int prime[PRIME_SIZE];

void sieve()
{
    int i,j,ind = 1,d;
    prime[ind++]=2;

    for(i=3;i<FLAG_SIZE;i+=2)
    {
        if(flag[i] == false)
        {
            prime[ind++]=i;

            if(i > FLAG_SIZE/i) ///cause i*i > FLAG_SIZE
                continue;

            for(j=i*i,d=i+i;j<=FLAG_SIZE;j+=d)
                flag[j]=true;
        }
    }
//    for(i=1;i<=100;i++)
//    {
//        printf("%d\n",prime[i]);
//    }
//    printf("Number of Prime : %d\n",ind);
}

struct node{
    int u,v;
};

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();
    vector<node>vec;
    int i,n,a,b;
    while(1==scanf("%d",&n))
    {
        int sz = 0,a,b;
        node x;
        for(i=2;i<=n;i++)
        {
            x.u = i-1;
            x.v = i;
            vec.pb(x);
        }
        x.u = 1;
        x.v = n;
        vec.pb(x);
        a = 1;
        sz = n;
        b = 2;
        int f = 0;
        while(!(flag[sz]==false && sz%2!=0))
        {
            if(f==0)
            {
                x.u = a;
                x.v = a+2;
                f = 1;
                a = a+1;
            }
            else
            {
                x.u = a;
                x.v = a+2;
                f = 1;
                a = a+3;
            }
            vec.pb(x);
            sz++;
        }
        cout<<sz<<endl;
        for(i=0;i<sz;i++)
            printf("%d %d\n",vec[i].u,vec[i].v);
    }

    return 0;
}
