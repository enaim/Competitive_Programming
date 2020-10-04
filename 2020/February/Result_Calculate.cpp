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
///  10th
///  Credit - > 135.000000    Total_Marks - > 430.067500   CGPA - > 3.185685
///  .Credit - > 135.000000    Total_Marks - > 434.567500   CGPA - > 3.219019
///  11th
///  Credit - > 147.000000    Total_Marks - > 472.817500   CGPA - > 3.216446
///  12th
///  Credit - > 159.000000    Total_Marks - > 512.192500   CGPA - > 3.221336

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double total_marks = 512.192500,credit = 159.000000;
//    double total_marks = 0,credit = 0;
    double c,m;

    while(true)
    {
        scanf("%lf%lf",&c,&m);
        total_marks += (c*m);
        credit += c;
        printf("Credit - > %.6f    Total_Marks - > %.6f   CGPA - > %.6f\n",credit,total_marks,total_marks/credit);
    }

    return 0;
}
