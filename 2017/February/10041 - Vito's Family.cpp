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

    int ar[510];
    int tks,ks=1,n,i,j,mx,sum;
    scanf("%d",&tks);
    while(tks--)
    {
        mx = OO;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        for(i=0;i<n;i++)
        {
            sum = 0;
            for(j=0;j<n;j++)
            {
                if(ar[i]>ar[j])
                    sum+=(ar[i]-ar[j]);
                else
                    sum+=(ar[j]-ar[i]);
            }
            if(mx>sum)
                mx = sum;
        }
        printf("%d\n",mx);
    }

    return 0;
}
