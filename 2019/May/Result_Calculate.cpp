#include<bits/stdc++.h>
using namespace std;

///  6th
///  Credit - > 85.75000    Total_Marks - > 251.44250   CGPA - > 2.93227
///  7th
///  Credit - > 99.250000    Total_Marks - > 299.817500   CGPA - > 3.020831
///  8th
///  Credit - > 115.000000    Total_Marks - > 351.567500   CGPA - > 3.057109
///  9th
///  Credit - > 123.250000    Total_Marks - > 379.317500   CGPA - > 3.077627
///  .Credit - > 123.250000    Total_Marks - > 396.567500   CGPA - > 3.217586


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double total_marks = 396.567500,credit = 123.250000;
//    double total_marks = 0,credit = 0;
    double c,m;

    while(true)
    {
        scanf("%lf%lf",&c,&m);
        total_marks += (c*m);
        credit += c;
        printf("Credit - > %.6lf    Total_Marks - > %.6lf   CGPA - > %.6lf\n",credit,total_marks,total_marks/credit);
    }

    return 0;
}
