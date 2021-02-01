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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,d,sum,a;

    while(2==scanf("%d%d",&n,&d))
    {
        sum = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            sum+=a;
        }
        int temp = ((n-1)*10)+ sum;
        int c = d - sum;

        if(temp <= d)
        {
            printf("%d\n",c/5);
        }
        else
            printf("-1\n");
    }

    return 0;
}
