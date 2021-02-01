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
#define sqr(a)  (a*a)

typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,b,c;
    while(3==scanf("%d%d%d",&a,&b,&c))
    {
        if(c==0)
        {
            if(a==b)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if((b-a)%c != 0 || (b-a)/c < 0)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
