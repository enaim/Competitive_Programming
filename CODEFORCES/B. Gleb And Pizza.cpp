#include<bits/stdc++.h>
using namespace std;


int main()
{
    int i,n;
    double x,y,rr,d,r;

    scanf("%lf%lf%d",&r,&d,&n);

    int cnt = 0;
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf%lf",&x,&y,&rr);
        double dis = sqrt(x*x + y*y);
        if(dis-rr >= r-d && dis+rr<=r)
            cnt++;
    }
    printf("%d\n",cnt);

    return 0;
}
