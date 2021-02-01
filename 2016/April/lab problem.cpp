#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <iostream>
#include <algorithm>

using namespace std;



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


//    int tks,ks=1;
//    scanf("%d",&tks);
//    while(tks--)
//    {
////        printf("Case %d: ",ks++);
//    }

    int x,n,i,sum;
    while(1==scanf("%d",&n))
    {
        sum = 1;
        x = 0;
        i = 3;
        while(i<=n)
        {
            if(x == 0)
            {
                sum -= i;
                x++;
            }
            else
            {
                sum+=i;
                x--;
            }
            i+=2;
        }
       printf("sum = %d\n",sum);
    }

    return 0;
}

