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

    int tks,ks=1;
    long long n,x;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        x = n%6;
        if(x==1)
            printf("1\n");
        else if(x == 2)
            printf("4\n");
        else if(x == 3)
            printf("6\n");
        else if(x == 4)
            printf("5\n");
        else if(x == 5)
            printf("2\n");
        else
            printf("0\n");
    }


    return 0;
}
