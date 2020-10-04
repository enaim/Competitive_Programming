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

    int n,i,mn,sum1,sum2,m;
    int ar[100010];
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        sort(&ar[0],&ar[n]);
        int mn1 = OO;
        for(i=0;i<n;i++)
        {
            if(i<n-1)
            {
                sum1 = ar[i]-1;
                sum2 = 1000000-ar[i+1];
                m =max(sum1,sum2);
                if(m<mn1)
                    mn1 = m;
            }
            else
            {
                sum1 = ar[i]-1;
                m = sum1;
                if(m<mn1)
                    mn1 = m;
            }
        }
        int mn2 = OO;
        for(i=n-1;i>=0;i--)
        {
            if(i<n-1)
            {
                sum1 = ar[i-1]-1;
                sum2 = 1000000-ar[i];
                m =max(sum1,sum2);
                if(m<mn2)
                    mn2 = m;
            }
            else if(i==0)
            {
                sum1 = 1000000-ar[i];
                m = sum1;
                if(m<mn2)
                    mn2 = m;
            }
        }

        printf("%d\n",min(mn1,mn2));
    }

    return 0;
}
