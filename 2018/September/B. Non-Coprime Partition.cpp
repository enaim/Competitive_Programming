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

    int n,sum1,sum2,i,sz,sz2;

    while(1==scanf("%d",&n))
    {
        sum1=sum2 = 0;
        vector<int>vec1,vec2;
        if(n<=2)
        {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        for(i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                sum2 = sum2+i;
                vec2.pb(i);
            }
            if(i%2!=0)
            {
                sum1 = sum1+i;
                vec1.pb(i);
            }
        }

        sz = vec1.size();
        sz2 = vec2.size();

        cout<<sz;
        for(i=0;i<sz;i++)
            printf(" %d",vec1[i]);
        printf("\n");
        cout<<sz2;
        for(i=0;i<sz2;i++)
            printf(" %d",vec2[i]);
        printf("\n");
    }

    return 0;
}
