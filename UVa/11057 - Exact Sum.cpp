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

    int ar[10010],ks = 1 ,n,m,i,j,ni,nj,mn;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        scanf("%d",&m);

            mn = OO;
            for(i=0;i<n;i++)
                for(j=i+1;j<n;j++)
                {
                    if((ar[i]+ar[j]) == m)
                    {
                        if(mn>abs(ar[i]-ar[j]))
                        {
                            mn = abs(ar[i]-ar[j]);
                            ni = i;
                            nj = j;
                        }
                    }
                }
        if(ar[ni]<ar[nj])
            printf("Peter should buy books whose prices are %d and %d.\n\n",ar[ni],ar[nj]);
        else
            printf("Peter should buy books whose prices are %d and %d.\n\n",ar[nj],ar[ni]);
        ks++;
    }

    return 0;
}
