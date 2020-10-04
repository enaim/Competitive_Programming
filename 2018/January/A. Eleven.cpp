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

ll ar[20000];


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll sum = 1,a=1;
    ll sum1 = 1,b=1;
    ar[1]=1;
    for(int i=0;i<20;i++)
    {
        sum = a;
        sum1 = b;
        sum = sum+sum1;
        ar[sum]=1;
        a = b;
        b = sum;
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(ar[i])
                printf("O");
            else
                printf("o");
        }
        printf("\n");
    }

    return 0;
}
