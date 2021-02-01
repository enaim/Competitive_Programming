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
}

int ar[500010];
vector<int>vec1,vec2;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();
    int i,j,n,x,f;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<n;i++)
        {
            f = 0;
            x = ar[i];
            for(j=1;prime[j]<=x/prime[j];j++)
                if(x%prime[j]==0)
                {
                    f = prime[j];
                    break;
                }
            int mul = 1;
            if(f!=0)
                while(x%f==0)
                {
                    mul*=f;
                    x/=f;
                }
            if(x>1 && mul>1)
            {
                vec1.pb(mul);
                vec2.pb(x);
            }
            else
            {
                vec1.pb(-1);
                vec2.pb(-1);
            }
        }
        for(i=0;i<n;i++)
            printf("%d ",vec1[i]);
        printf("\n");
        for(i=0;i<n;i++)
            printf("%d ",vec2[i]);
        printf("\n");
    }

    return 0;
}
