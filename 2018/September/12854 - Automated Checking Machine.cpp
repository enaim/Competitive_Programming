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

    int i,ar[10];

    while(5==scanf("%d%d%d%d%d",&ar[0],&ar[1],&ar[2],&ar[3],&ar[4]))
    {
        scanf("%d%d%d%d%d",&ar[5],&ar[6],&ar[7],&ar[8],&ar[9]);
        for(i=0;i<5;i++)
            if(ar[i]==ar[i+5])
                break;
        if(i==5)
            printf("Y\n");
        else
            printf("N\n");
    }

    return 0;
}
