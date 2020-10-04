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


    int i,j,n,s,d,mx;
    int ar[1010];

    while(1==scanf("%d",&n))
    {

        mx = 0;
        for(i=0;i<n;i++)
        {
             scanf("%d%d",&s,&d);
             while(mx>=s)
                s+=d;
             mx = s;
        }
        printf("%d\n",mx);
    }

    return 0;
}
