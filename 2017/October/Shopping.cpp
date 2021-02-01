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


    int tks,ks=1,tk,sum,i,x,n;
    scanf("%d",&tks);
    while(tks--)
    {
        sum = 0;
        scanf("%d%d",&tk,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            sum+=x;
        }
        if(sum<=tk)
            printf("Go for shopping\n");
        else
            printf("You don't have enough money\n");
    }

    return 0;
}
