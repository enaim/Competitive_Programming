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


    int j,n,k,x,sum,i;
    int ar[110];
    while(3==scanf("%d%d%d",&n,&k,&x))
    {
        int sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            sum+=ar[i];
        }
        i--;
        for(j=0;j<k;j++)
        {
            sum-=ar[i-j];
            sum+=x;

        }
        printf("%d\n",sum);
    }

    return 0;
}
