#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,n,x;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);

        x = n/5;
        if(n%5 !=0)
            printf("%d\n",x+1);
        else
            printf("%d\n",x);

    }

    return 0;
}
