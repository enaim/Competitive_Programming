#include<bits/stdc++.h>
using namespace std;


const double pi = acos(-1.0);

int main()
{
    double a,n,x,z,aos,aoa,aot,s,temp,temp1,fs,sr,ds;

    while(scanf("%lf",&a)==1)
    {
        aos = a*a; // area of square;
        aoa = (pi*aos)/4.0;   // area of arc;
        s = (a+a+a)/2.0;
        aot = sqrt(s*(s-a)*(s-a)*(s-a));     // area of triangle
        x = ((pi*aos)/6.0)-aot; // arc which is out of triangle
        z = aot+x+x;                 // triangle + 2 extended arc
        n = aos - ((aos - aoa)*2);   // boat
        temp = z - n;                // free space one
        fs = temp*4.0;
        temp1 = fs+(2.0*n);
        sr = temp1 - aos;            // stripe region
        ds = aos - fs - sr;          //dot region

        printf("%.3lf %.3lf %.3lf\n",sr,ds,fs);
    }

    return 0;
}
