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

    int i,j,n,s,cnt,sz;
    while(1==scanf("%d",&n))
    {
        sz = 0;
        s = sqrt(n);
        cnt =   n+1-s;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=s;j++)
            {
                printf("%d ",cnt++);
                sz++;
            }
            if(n-sz<s)
                break;
            cnt =  cnt-(2*s);
        }
        for(i=1;i<=n-sz;i++)
            printf("%d ",i);
        printf("\n");
    }

    return 0;
}
