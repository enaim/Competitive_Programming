#include <stdio.h>
#include <string.h>
#include <math.h>


const double pi = acos(-1.0);

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double Ax,Ay,Bx,By,Ox,Oy,c,tks,ks=1,r,cir,div,C,angle_O,cos_O;
    scanf("%lf",&tks);
    while(ks <= tks)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&Ox,&Oy,&Ax,&Ay,&Bx,&By);

        r = sqrt((pow((Ox-Ax),2)) + (pow((Oy-Ay),2)));
        c = sqrt((pow((Ax-Bx),2)) + (pow((Ay-By),2)));
        cir = 2*pi*r;

        cos_O=((r*r)+(r*r)-(c*c))/(2*r*r);
        angle_O = acos(cos_O);

        div = (2*pi)/angle_O;
        C = cir/div;

        printf("Case %0.lf: %lf\n",ks++,C);
    }

    return 0;
}

