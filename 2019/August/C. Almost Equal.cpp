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

    int i,n,x,f,sz1,sz2;
    while(1==scanf("%d",&n))
    {
        vector<int>v1,v2;
        if(n%2==0)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        if(n==1)
        {
            printf("1 2\n");
            continue;
        }
        x = 1;
        v1.pb(1);

        f = 1;
        while(x<2*n)
        {
            if(f==1)
            {
                x++;
                v2.pb(x);
                x++;

                if(x<=2*n)
                v2.pb(x);

                f = 0;
            }
            else
            {
                f = 1;

                x++;
                v1.pb(x);

                x++;
                if(x<=2*n)
                v1.pb(x);
            }
        }
        f = 0;
        for(i=0;i<n;i++)
            printf("%d ",v1[i]);
        for(i=0;i<n;i++)
            printf("%d ",v2[i]);
        printf("\n");
    }

    return 0;
}
