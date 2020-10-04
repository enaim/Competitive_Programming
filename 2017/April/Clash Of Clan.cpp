//https://www.hackerrank.com/contests/bubt/challenges/clash-of-clan

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

struct coc{
        char s[100];
        int t;
};

bool compare(coc a,coc b)
{
    return a.t > b.t;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    coc ar[10010];
    int i,n;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%s%d",ar[i].s,&ar[i].t);
        sort(&ar[0],&ar[n],compare);

        for(i=0;i<n;i++)
        {
            printf("Rank %d# : %s\n",i+1,ar[i].s);
        }

        printf("\n");
    }

    return 0;
}
