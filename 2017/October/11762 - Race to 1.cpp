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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const int SIZE = 1000010;
const int Size = 80000;

bool flag[SIZE];
int prime[Size];
double dp[SIZE];

void Sieve()
{
    int ind = 1,d,i,j;
    prime[ind++] = 2;

    for(i=3;i<SIZE;i+=2)
    {
        if(flag[i] == false)
        {
            prime[ind++] = i;

            if(i > SIZE/i)
                continue;

            for(j=i*i,d=i+i;j<SIZE;j+=d)
                flag[j]=true;
        }
    }
}


double Race(int n)
{
    int i;
    if(n==1)
        return 0;

    double &re = dp[n];
    if(re != -1)
        return re;
    re = 0.0;
    int cnt=0;

    for(i=1;prime[i]<=n;i++)
    {
        re+=1;
        if(n%prime[i] == 0)
            re += (Race(n/prime[i]));
        else
            cnt++;
    }

    double ans = 1.0-(cnt/(i-1.0));

    return re = (re/ans)*(1.0/(i-1.0));
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Sieve();

    for(int i=0;i<=SIZE;i++)
        dp[i]= -1;

    int tks,ks=1,n;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);

        double res = Race(n);
        printf("Case %d: %.10lf\n",ks++,res);
    }

    return 0;
}
