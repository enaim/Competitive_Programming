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


long long pow(long long x,long long n)
{
    long long ans = 1;
    for(int i = 1;i<=n;i++)
        ans*=x;

    return ans;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long n,k,i,temp,x,y,z;

    while(2==scanf("%I64d%I64d",&n,&k))
    {
        if(k%2 != 0)
            printf("1\n");
        else if(k==2)
            printf("2\n");
        else
        {
            for(i=2;i<=50;i++)
            {
                temp = pow(2,i);
                x = k%temp;
                y = k/temp;
                z = pow(2,i-1);
                if(x == 0 && y == 1)
                {
                    printf("%I64d\n",i+1);
                    break;
                }
                else if(x == z)
                {
                    printf("%I64d\n",i);
                    break;
                }
            }
        }
    }

    return 0;
}
