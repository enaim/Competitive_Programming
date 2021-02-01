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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)
#define sqr(a)  (a*a)

typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

int const Size = 400;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,k,n,x,temp,sum,ans,sum1,sum2;
    int ar[Size];
    char str[Size];

    while(1==scanf("%d",&n))
    {
        sum =0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            sum+=ar[i];
        }
        ans = OO;
        for(i=0;i<n;i++)
        {
            sum1 = 0;
            for(j=0;j<n;j++)
            {
                if(i+j>=n)
                    sum1 += ar[i+j-n];
                else
                    sum1 += ar[i+j];

                sum2 = sum-sum1;
                x = abs(sum1-sum2);
                if(ans>x)
                    ans = x;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
