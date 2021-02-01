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


    int tks,ks=1,n,x,i;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        double sum = 0.0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            sum+=x;
        }

        printf("%.10lf\n",sum/n);
    }

    return 0;
}
