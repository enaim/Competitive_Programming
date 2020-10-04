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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

    int ar[2010];
    int n,x,i,sum,mx;

    while(1==scanf("%d",&n))
    {
        x = 1e6;
        mx = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            mx = max(mx,ar[i]);
        }
        sum = 1e6-mx;
        for(i=0;i<n;i++)
            ar[i]+=sum;
        printf("%d\n",n+1);
        printf("1 %d %d\n",n,sum);
        for(i=0;i<n;i++)
        {
            x = ar[i] - i;
            ar[i] = ar[i]%x;
            printf("2 %d %d\n",i+1,x);
        }
    }

    return 0;
}
