#include<bits/stdc++.h>
using namespace std;


int main()
{

//    freopen("in.txt","r",stdin);

    int tks,ks;
    double avg,a,b,c,d,e,f,g,sum;

    scanf("%d",&tks);
    ks = 1;
    while(tks--)
    {
        sum = 0;
        scanf("%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f,&g);

        if(e<=f && e<=g)
            avg = (f+g)/2.0;
        else if(f<=e && f<=g)
            avg = (e+g)/2.0;
        else
            avg = (e+f)/2.0;

        sum = a+b+c+d+avg;

//        printf("%lf\n",avg);
        if(sum>=90)
            printf("Case %d: A\n",ks++);
        else if(sum>=80)
            printf("Case %d: B\n",ks++);
        else if(sum>=70)
            printf("Case %d: C\n",ks++);
        else if(sum>=60)
            printf("Case %d: D\n",ks++);
        else
            printf("Case %d: F\n",ks++);
    }


    return 0;
}
