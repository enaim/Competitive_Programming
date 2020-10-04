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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,cnt = 0,i,j,k;
    while(1==scanf("%d",&n))
    {
        cnt = 0;
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
                {
                    if((i+j)>(i^j) && i <= j && j<=(i^j) && (i^j)<=n)
                    {
                        cnt++;
                    }
                }

        printf("%d\n",cnt);
    }
    return 0;
}
