#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double a,b;

    cin>> a >> b;


    printf("%.14lf\n%.14lf\n",a,b);

    if(fabs(a-b) < 1e-8)
        printf("EQUAL\n");
    else
        puts("Not Equal");

    char s[22];
    cin >> s;
    puts(s);

    return 0;
}
