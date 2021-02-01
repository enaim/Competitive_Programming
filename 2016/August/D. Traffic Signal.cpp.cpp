#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,a,b,c,d;
    double x;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);

        if(c == 1 && d == 1)
            printf("E-W Green\n");
        else if(a==0 && b==0 && c==0 &&d ==0)
            printf("N-S Green\n");

        else if((c==1 || d==1) && (a == 1 && b == 1))
            printf("N-S Green\n");

        else if((a==1 || b==1) && (c==0 && d==0))
            printf("N-S Green\n");
        else
            printf("E-W Green\n");

    }

    return 0;
}

