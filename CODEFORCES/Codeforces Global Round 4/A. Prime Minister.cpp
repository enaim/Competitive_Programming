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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

    int i,n,ar[1010];
    while(1==scanf("%d",&n))
    {
        int sum = 0;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]),sum+=ar[i];
        int x = ar[0];
        int cnt = 1;
        for(i=1;i<n;i++)
            if(ar[i]*2<=ar[0])
                x+=ar[i],cnt++;
        int a = sum-x;
        if(a>=x)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n1 ",cnt);
        for(i=1;i<n;i++)
            if(ar[i]*2<=ar[0])
                printf("%d ",i+1);
            printf("\n");
    }

    return 0;
}
