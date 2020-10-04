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

const int FLAG_SIZE = 32000;
const int PRIME_SIZE = 80000;


bool flag[FLAG_SIZE];
int prime[PRIME_SIZE];


void sieve()
{
    int ind = 1,i,j;
    double d;

    prime [ ind++ ]  = 2;

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

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();

    int p,y,i,j,ind;
    while(2==scanf("%d%d",&p,&y))
    {
        ind = 0;
        for(i=1;i<=3433;i++)
        {
            if(prime[i]>p)
            {
                ind = i;
                break;
            }
        }
        if(ind==0)
            ind = 3433;
        if(y%2==0)
            y--;
        bool x=false;
        for(j=y;j>p;j-=2)
        {
            for(i=1;i<ind;i++)
            {
                if(j%prime[i]==0)
                    break;
            }
            if(i==ind)
            {
                x = true;
                break;
            }
        }
        if(x)
            printf("%d\n",j);
        else
            printf("-1\n");
    }

    return 0;
}
