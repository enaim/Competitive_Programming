#include <stdio.h>
#include <string.h>

double getMin(int n,double a[])
{
    double m;

    m = a[0];

    for(int i=1;i<n;i++)
    {
        if(m > a[i])
            m=a[i];
    }

    return m;
}



int main()
{
    double arr[100],x;
    int na,i;


    while(1 == scanf("%d",&na))
    {
        for(i=0;i<na;i++)
            scanf("%lf",&arr[i]);

        x = getMin(na,arr);

        printf("%lf\n",x);
    }

    return 0;
}
