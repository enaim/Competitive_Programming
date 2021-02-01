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

    int ar[500010];
    int n,i;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        sort(&ar[0],&ar[n]);
        int mid = n/2;
        int ans = n;

        for(i=0;i<n/2;i++)
        {
            while(true)
            {
                if(ar[i]*2 <= ar[mid])
                {
                    ans--;
                    mid++;
                    break;
                }
                else
                    mid++;

                if(mid == n)
                    break;
            }
            if(mid == n)
                break;
        }
        printf("%d\n",ans);
    }

    return 0;
}
