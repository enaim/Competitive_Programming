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

    int s,a,b,c,d,a1,a2;

    while(5==scanf("%d%d%d%d%d",&s,&a,&b,&c,&d))
    {
        a1 = (2*c) + (s*a);
        a2 = (2*d) + (s*b);

        if(a1 < a2)
            printf("First\n");
        else if(a1 > a2)
            printf("Second \n");
        else
            printf("Friendship\n");
    }

    return 0;
}
