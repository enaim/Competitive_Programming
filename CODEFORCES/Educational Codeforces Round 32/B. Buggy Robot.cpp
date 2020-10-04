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

    int ans,m1,m2,i,a,b,c,d;
    while(1==scanf("%d",&n))
    {
        a = b = c =d =0;
        scanf("%s",str);
        for(i=0;i<n;i++)
        {
            if(str[i]=='R') a++;
            if(str[i]=='L') b++;
            if(str[i]=='U') c++;
            if(str[i]=='D') d++;
            if(a<b)
                m1 = a;
            else
                m1 = b;
            if(c<d)
                m2 = c;
            else
                m2 = d;
        }
        printf("%d\n",(m1+m2)*2);
    }

    return 0;
}
