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

const int Size = 110;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,x,z,ans,sum,temp,a,b;
    int ar[Size];
    char str[Size];

    while(1==scanf("%d",&n))
    {
        a = 1;
        b = 2;
        temp = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x==a || x==b)
            {
                if(x==1)
                {
                    if(a==2)
                        b=3;
                    else if(a==3)
                        b=2;
                    else if(b==2)
                        b=3;
                    else if(b==3)
                        b=2;
                    a = 1;
                }
                if(x==2)
                {
                     if(a==1)
                        b=3;
                    else if(a==3)
                        b=1;
                    else if(b==1)
                        b=3;
                    else if(b==3)
                        b=1;
                    a = 2;
                }
                if(x==3)
                {
                    if(a==2)
                        b=1;
                    else if(a==1)
                        b=2;
                   else  if(b==2)
                        b=1;
                    else if(b==1)
                        b=2;
                    a = 3;
                }
            }
            else
                temp = 1;
        }

        if(temp)
            printf("No\n");
        else
            printf("YES\n");
    }

    return 0;
}
