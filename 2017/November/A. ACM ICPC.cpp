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

    int a,b,c,n,x,temp,i,j,k;
    int ar[10];
    char str[110];

        int sum = 0;
        for(i=0;i<6;i++)
        {
            scanf("%d",&ar[i]);
            sum+=ar[i];
        }
        temp = 0;
        if(sum%2 == 0)
            temp = 1;

        if(temp == 1)
        {
            sum = sum/2;
            x = 0;
            for(i=0;i<6;i++)
                for(j=i+1;j<6;j++)
                    for(k=j+1;k<6;k++)
                        if((ar[i] + ar[j] + ar[k]) == sum)
                        {
                            x=1;
                        }
        }
        if(x==0 || temp == 0)
            printf("NO\n");
        else
            printf("YES\n");

    return 0;
}
