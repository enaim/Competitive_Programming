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
const int FLAG_SIZE = 400010;
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

int f[5];
int i,x,y,dif,ind,sum,n;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();

    while(1==scanf("%d",&n))
    {
        f[1]=f[2]=0;
        for(i=0;i<n;i++)
            scanf("%d",&x),f[x]++;

        ind = 1;
        sum = 0;
        while(f[1] && f[2])
        {
            dif = prime[ind]-sum;
            x = dif/2;
            y = dif%2;
            for(i=0;i<x;i++)
            {
                if(f[2])
                    printf("2 "),f[2]--,sum+=2;
                else
                    break;
            }
            for(i=0;i<y;i++)
            {
                if(f[1])
                    printf("1 "),f[1]--,sum+=1;
                else
                    break;
            }
            ind++;
        }
        for(i=0;i<f[1];i++)
            printf("1 ");
        for(i=0;i<f[2];i++)
            printf("2 ");
        printf("\n");
    }

    return 0;
}
