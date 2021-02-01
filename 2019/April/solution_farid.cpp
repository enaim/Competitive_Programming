#include<bits/stdc++.h>
using namespace std;

const int mx = 123456;
const double pi = acos(-1.0);

double DEG_to_RAD(double d) { return d * pi / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / pi; }


int main(){
    int tk=1,cs=0;
    // freopen("in.txt","r", stdin);
    // freopen("out.txt","w", stdout);

    scanf("%d",&tk);
    while(tk--){
        double r1,r2,r3,res = 0.0;
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        double A = 0.0,s,a1,a2,a3;
        r1 = r1/2.0 , r2 = r2/2.0, r3 = r3/2.0;
        a1 = r1 + r2;
        a2 = r1 + r3;
        a3 = r2 + r3;

        s = (a1+a2+a3) / 2.0;
        A = sqrt(s *abs(s-a1)*abs(s-a2)*abs(s-a3)); // Area of triangle
//        cerr<<s<<' '<<A<<endl;
        double n1,n2,n3;               // A= 1/2 *ab sin(ang)
        n1 = asin((A*2.0)/(a1*a2));
        n2 = asin((A*2.0)/(a1*a3));
        n3 = asin((A*2.0)/(a2*a3));
//        cerr<<n1<<' '<<n2<<' '<<n3<<endl;
//        n1 = RAD_to_DEG(n1);
//        n2 = RAD_to_DEG(n2);
//        n3 = RAD_to_DEG(n3);
//        cerr<<n1<<' '<<n2<<' '<<n3<<endl;
        double b1,b2,b3;
        b1 = n1*r1*r1/2.0;
        b2 = n2*r2*r2/2.0;
        b3 = n3*r3*r3/2.0;
        res = A - ( b1+b2+b3);
//        cerr<<b1<<' '<<b2<<' '<<b3<<endl;
       printf("Case %d: %.3f\n",++cs,res);
     }

return 0;
}
