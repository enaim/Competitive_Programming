#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//  6th
//  Credit - > 85.75000    Total_Marks - > 251.44250   CGPA - > 2.93227
//  7th
//  Credit - > 99.250000    Total_Marks - > 299.817500   CGPA - > 3.020831
//  8th
//  Credit - > 115.000000    Total_Marks - > 351.567500   CGPA - > 3.057109
//    double total_marks = 351.567500,credit = 115.000000;
    double total_marks = 351.567500+17.25,credit = 115.000000;
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
