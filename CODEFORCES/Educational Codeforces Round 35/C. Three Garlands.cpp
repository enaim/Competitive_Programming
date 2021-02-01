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
#define OO (1<<25)

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

    int n,i,x;
    int ar[5];
    while(3==scanf("%d%d%d",&ar[0],&ar[1],&ar[2]))
    {
        sort(&ar[0],&ar[3]);
        if(ar[0]==1)
            printf("YES\n");
        else if(ar[0]==2 && ar[1]==2)
            printf("YES\n");
        else if(ar[0]==ar[1] && ar[1]==ar[2] && ar[2]==3)
            printf("YES\n");
        else if(ar[0]==2 && ar[1]==4 && ar[2]==4)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
