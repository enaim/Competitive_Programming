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

    int a,b,n,i,ans;
    while(3==scanf("%d%d%d",&n,&a,&b))
    {
        int z = 1;
        ans = max(a,b);
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            if(max(a,b)<=ans)
                ans = max(a,b);
            else if(min(a,b)<=ans)
                ans = min(a,b);
            else
                z = 0;
        }
        if(z)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
