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

    int n,cnt1,cnt2,ind,ind1,i;
    int ar[110];
    while(1==scanf("%d",&n))
    {
        cnt1 = cnt2 = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            if(ar[i] % 2 == 0)
            {
                cnt1++;
                ind = i;
            }
            else
            {
                cnt2++;
                ind1 = i;
            }
        }
        if(cnt1 == 1)
                printf("%d\n",ind+1);
            else
                printf("%d\n",ind1+1);
    }

    return 0;
}
