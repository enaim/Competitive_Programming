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


    int tks,ks = 1;
    int n,x,i,j;
    int dp[7500];
    int coin[] = {1,5,10,25,50};
    
    memset(dp,0,sizeof dp);
    dp[0] = 1;

    for(i=0;i<5;i++)
    {
        x = coin[i];
        for(j=x;j<7490;j++)
        {
            dp[j] = dp[j-x] + dp[j];
        }
    }

    while(scanf("%d",&n)==1)
    {        
        printf("%d\n",dp[n]);
    }

    return 0;
}
