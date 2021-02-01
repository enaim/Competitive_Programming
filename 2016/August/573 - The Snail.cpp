#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);

    double h,u,d,f,cnt,total,x;

    while(4 == scanf("%lf%lf%lf%lf",&h,&u,&d,&f) && h)
    {
        cnt = 0;
        total = 0;
        x = (u*f)/100;
        while(total < h)
        {
            if(u > 0)
                total += u;
            cnt++;

            if(total > h)
                break;

            total-=d;
            u-=x;
            if(total <0)
                break;
        }
        if(total >= h)
           printf("success on day %.0lf\n",cnt);
        else
            printf("failure on day %.0lf\n",cnt);
    }

    return 0;
}
