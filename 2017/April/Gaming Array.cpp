//https://www.hackerrank.com/contests/bubt/challenges/an-interesting-game-1

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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    long long ar[100010],mx[100010],m,mxm,cnt,i,x,n;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        mxm=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
            {
                if(ar[i] > mxm)
                {
                    mxm = ar[i];
                    mx[i]=i;
                    m = i;
                }
                else
                    mx[i]=m;
            }
        }
        cnt = 0;
        n--;
        while(n>0)
        {
            x = mx[n];
            n = x-1;
            cnt++;
        }
        if(n==0)
            cnt++;

        if(cnt%2==0)
            printf("ANDY\n");
        else
            printf("BOB\n");
    }

    return 0;
}
