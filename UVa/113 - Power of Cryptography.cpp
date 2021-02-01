#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double n,p,ans;

    while(2==scanf("%lf%lf",&n,&p))
    {
        ans = pow(p,1/n);
        printf("%.0lf\n",ans);
    }

    return 0;
}

