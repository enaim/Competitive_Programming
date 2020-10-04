#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,m,n,male;
    double x;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf",&x);

        printf("%.4lf\n",(x+10)/7);
    }


    return 0;
}

