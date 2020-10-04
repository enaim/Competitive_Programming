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

    int i,cnt,s,r,n,g;
    int ar[100010];

    while(2==scanf("%d%d",&n,&g))
    {
        long long sum = 0;
        cnt = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&s,&r);
            if(s<r)
                ar[cnt++] = r-s;
            else if(s==r)
            {
                if(g)
                {
                    sum+=3;
                    g--;
                }
                else
                    sum+=1;
            }
            else
                sum+=3;
        }

        if(g)
        {
            sort(&ar[0],&ar[cnt]);

            for(i=0;i<cnt;i++)
            {
                if(g>ar[i])
                {
                    sum+=3;
                    g-=(ar[i]+1);
                }
                else if(g==ar[i])
                {
                    sum+=1;
                    g = 0;
                }
                else
                    g = 0;

                if(g<=0)
                    break;
            }
        }
        printf("%lld\n",sum);
    }

    return 0;
}
