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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int n;
    int ar[1010],cnt,i;
    while(1==scanf("%d",&n))
    {
        cnt = 0;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=1;i<n-1;i++)
            if((ar[i] > ar[i-1] && ar[i] > ar[i+1] ) || (ar[i] < ar[i-1] && ar[i] < ar[i+1] ))
                cnt++;
        printf("%d\n",cnt);
    }

    return 0;
}
