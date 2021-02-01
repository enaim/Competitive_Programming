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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,d,m,y,t,k,r,sum,sum1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d",&d,&m,&y);
        scanf("%d%d%d",&t,&r,&k);
        sum = 12+8*30+2018*365;
        sum1 = d+m*30+y*365;
        if(sum1<=sum)
            printf("Case %d: Expired.\n",ks++);
        else if(t-k<r)
            printf("Case %d: Invalid.\n",ks++);
        else
        {
            printf("Case %d: Valid.\n",ks++);
            printf("Total Penalty Money: %d$.\n",(k*(k+1))*5);
        }
    }

    return 0;
}
