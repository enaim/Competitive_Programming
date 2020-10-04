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
    ll d;

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

bool func(int n)
{
    if(n==1)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    if(n<FLAG_SIZE)
    {
        if(flag[n]==true)
            return false;
        else
            return true;
    }

    int x = sqrt(n),i;
    for(i=1;i<4800 && prime[i]<=x;i++)
    {
        if(n%prime[i]==0)
            return false;
    }
    return true;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();
    int l,u,sz,i,j,ans1,ans2,ans3,ans4,mn,mx,cnt,last;

    while(2==scanf("%d%d",&l,&u))
    {
        mn = 2147483647;
        mx = -214;
        last = -1;
        cnt = 0;

        if(l==1)
            l++;

        if(l%2==0)
        {
            if(func(l))
            {
                last = l;
                cnt++;
            }
            l++;
        }

        for(ll i=l;i<=u;i+=2)
        {
            if(func(i))
            {
                cnt++;
                if(last == -1)
                {
                    last = i;
                    continue;
                }

                if(i-last<mn)
                {
                    mn = i-last;
                    ans1 = last;
                    ans2 = i;
                }
                if(i-last>mx)
                {
                    mx = i-last;
                    ans3 = last;
                    ans4 = i;
                }
                last = i;
            }
        }
        if(cnt<=1)
            printf("There are no adjacent primes.\n");
        else
            printf("%d,%d are closest, %d,%d are most distant.\n",ans1,ans2,ans3,ans4);
    }

    return 0;
}
