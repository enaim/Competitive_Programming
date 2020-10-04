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


    int n,cnt = 0,k;
    while(1==scanf("%d",&n))
    {
        while(1 == scanf("%d",&k) && k> -1)
        {
            if( (n & (1<<k) )> 0)
            {
                puts("Yes");
            }
            else {
                puts("No");
            }
        }
    }

    return 0;
}
