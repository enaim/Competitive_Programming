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


    int tks,ks=1,a,b,c,n,x,y,sum,i;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&n);

        x = b - a;
        y = c - b;

        sum = a;
        if(x==y)
        {
            for(i=0;i<n-1;i++)
            {
                sum += x;
            }
            printf("Case %d: %d\n",ks++,sum);
        }
        else
            printf("Case %d: Error\n",ks++);

    }

    return 0;
}
