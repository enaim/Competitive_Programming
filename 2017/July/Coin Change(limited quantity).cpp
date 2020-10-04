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

// a problem with 5 different value's coins ( 1 5 10 25 50) and every coin has a own quantity ..... 
// with use this coins a amount is possible or not ?? 

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks = 1,n,x,i,j,k;
    int dp[10010],ar[5];
    int coin[] = {1,5,10,25,50};
    
    memset(dp,0,sizeof dp);
    dp[0] = 1;

    while(true)
    {       
        for(i=0;i<5;i++)
            scanf("%d",&ar[i]);

        for(i=0;i<5;i++)
            for(j=0;j<ar[i];j++)
                for(k=10000;k>=0;k--)
                {
                    x = k - coin[i];
                    if(dp[x] == 1 && x>=0)
                        dp[k] = 1;
                }

        while(scanf("%d",&n)==1)
        {
            if(dp[n])
                printf("Possible\n");
            else
                printf("Not Possible\n");
        }
    }


    return 0;
}
