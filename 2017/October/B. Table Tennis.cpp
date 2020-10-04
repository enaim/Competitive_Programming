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
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long ar[510],br[510],n,ind,i,k;

    while(2==scanf("%lld%lld",&n,&k))
    {
        memset(br,0,sizeof br);
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i]);

        if(ar[0]>ar[1])
            ind = 0;
        else
            ind = 1;
        br[ind] ++;

        for(i=2;i<n;i++)
        {
            if(br[ind] == k)
                break;
            if(ar[i]>ar[ind])
            {
                br[ind] = 0;
                ind = i;
            }
            br[ind]++;
        }
        printf("%lld\n",ar[ind]);
    }

    return 0;
}
