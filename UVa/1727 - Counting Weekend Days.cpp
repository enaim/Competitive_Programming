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
#include <queue>

using namespace std;

#define pb push_back

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    string d,mn;
    int tks,ks=1,h,rem,x,y,day,month;
    scanf("%d",&tks);
    while(tks--)
    {
        cin>>mn>>d;

        if(mn == "JAN" || mn == "MAR" || mn =="MAY" ||
           mn == "JUL" || mn == "AUG" ||
           mn == "OCT" || mn == "DEC")
            month = 31;
        else if(mn == "FEB")
            month = 28;
        else
            month = 30;

        if(d == "SUN")
            day = 1;
        else if(d == "MON")
            day = 2;
        else if(d == "TUE")
            day = 3;
        else if(d == "WED")
            day = 4;
        else if(d == "THU")
            day = 5;
        else if(d == "FRI")
            day = 6;
        else if(d == "SAT")
            day = 7;

        h = 8;
        x = 28;
        y = day;
        while(x != month)
        {
            if(y==6 || y==7)
                h++;
            y++;
            x++;
        }
        printf("%d\n",h);
    }

    return 0;
}
