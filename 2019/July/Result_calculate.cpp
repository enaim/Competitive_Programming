#include<bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    double total_marks = 434.567500,credit = 135.000000;
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
