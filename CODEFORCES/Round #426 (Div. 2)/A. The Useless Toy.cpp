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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    map<int,int>mp1,mp2;
    mp1[118] = 1;
    mp1[60] = 2;
    mp1[94] = 3;
    mp1[62] = 4;

    mp2[118] = 4;
    mp2[60] = 3;
    mp2[94] = 2;
    mp2[62] = 1;

    char a[10],b[10];
    int i,x,y,ans,n;
    while(3==scanf("%s%s%d",a,b,&n))
    {
        x = y = 0;
        n = n%4;

        if(mp1[a[0]] + n > 4)
        {
            ans = mp1[a[0]] + n - 4;
        }
        else
            ans = mp1[a[0]] + n;

        if(mp1[b[0]] == ans)
            x = 1;


        if(mp2[a[0]] + n > 4)
        {
            ans = mp2[a[0]] + n - 4;
        }
        else
            ans = mp2[a[0]] + n;

        if(mp2[b[0]] == ans)
            y = 1;


        if(x==1 && y==1)
            printf("undefined\n");
        else if(y==1)
            printf("ccw\n");
        else if(x==1)
            printf("cw\n");
        }

    return 0;
}
