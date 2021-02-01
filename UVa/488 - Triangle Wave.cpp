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

    int n,t,i,j,r=0,T,cnt;
    scanf("%d",&T);

    while(r<T)
    {
        if(r)
            printf("\n");
        scanf("%d",&n);
        scanf("%d",&t);
        cnt=0;
        while(cnt<t)
        {
            for(i=1;i<=n;i++)
            {
                for(j=i;j>0;j--)
                    printf("%d",i);
                printf("\n");
            }

            for(i=n-1;i>0;i--)
            {
                for(j=i;j>0;j--)
                    printf("%d",i);
                printf("\n");
            }
            cnt++;

            if(cnt ==  t)
                continue;
            printf("\n");
        }
        r++;
    }

    return 0;
}

