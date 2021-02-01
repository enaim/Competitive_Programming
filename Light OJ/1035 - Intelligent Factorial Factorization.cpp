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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n,i,x,sum;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        int t = 1;
        printf("Case %d:",ks++);
        for(i=0;i<25 && prime[i]<=n;i++,t++)
        {
            x = prime[i];
            sum = 0;
            while(x<=n)
            {
                sum+=(n/x);
                x*=prime[i];
            }
            if(t==1)
                printf(" %d = %d (%d)",n,prime[i],sum);
            else
                printf(" * %d (%d)",prime[i],sum);
        }
        printf("\n");
    }

    return 0;
}
