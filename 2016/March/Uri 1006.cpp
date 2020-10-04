#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    double A,B,C,result;

    while(3==scanf("%lf%lf%lf",&A,&B,&C))
    {
        result = ((A*2)+(B*3)+(C*5))/(2+3+5);

        printf("MEDIA = %.1lf\n",result);
    }

    return 0;
}

