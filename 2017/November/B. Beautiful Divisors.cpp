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
#define sqr(a)  (a*a)

typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[10],n,i;
    ar[7] = 32640;
    ar[6] = 8128;
    ar[5] = 2016;
    ar[4] = 496;
    ar[3] = 120;
    ar[2] = 28;
    ar[1] = 6;
    ar[0] = 1;

    while(1==scanf("%d",&n))
    {
        for(i=7;i>=0;i--)
            if(n%ar[i]==0)
                break;
        printf("%d\n",ar[i]);;
    }

    return 0;
}
