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
const int FLAG_SIZE = 1001000;
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
}
/*
1. 1 is co-prime with every number.
2. Every prime number is co-prime to each other.
3. Any two successive numbers/integers(consecutive number) are always co-prime.
4. The sum of any two co-prime numbers are always co-prime with their product
((2+3)and(2×3).Hence,5 and 6 are co-prime to each other).
5. Number of co-prime from 1 to any prime number is p-1.
*/

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sieve();
    int n,res,i;
    while(1==scanf("%d",&n))
    {
//        if n is not a prime number
        res = n;
        for(i=1;prime[i]<=n;i++)
        {
            if(n%prime[i]==0)
            {
                res/=prime[i];
                res*=(prime[i]-1);
            }
        }
        printf("Number of co-prime from 1 to n-1 -> %d\n",res);
    }

    return 0;
}
