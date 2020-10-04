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

    int n,i,j,x,y,age;
    int ar[101];
    while(1==scanf("%d",&n) && n)
    {
        memset(ar,0,sizeof ar);
        x =0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&age);
            for(j=1;j<=99;j++)
            {
                if(j == age)
                {
                    ar[j]+=1;
                    if(j>x)
                        x=j;
                    break;
                }
            }
        }
        y = ar[x];
        for(i=1;i<=99;i++)
            for(j=1;j<=ar[i];j++)
            {
                if(i == x && j == y)
                    printf("%d",i);
                else
                    printf("%d ",i);
            }
            printf("\n");
    }

    return 0;
}

