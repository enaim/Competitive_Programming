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

    int  h,m;
    double a,b,c,d,ans,ans1,ans2,temp,t;

    while(6==scanf("%d%d%lf%lf%lf%lf",&h,&m,&a,&b,&c,&d))
    {
        ans = 0;
        if(h<20)
        {
            ans2 = (int)a/(int)d;
            if(a-(ans2*d) > 0.0)
                ans2++;
            ans2*=c;
            c = (c/100.0)*80.0;

            temp = a;
            t = ((19.0-h)*60)+(60-m);
            temp+=(b*t);
            ans1 = (int)temp/(int)d;
            if(temp-(ans1*d)>0.0)
                ans1+=1;
            ans1*=c;
            ans = min(ans1,ans2);
        }
        else
        {
            c = (c/100.0)*80.0;
            ans = (int)a/(int)d;
            if(a-(ans*d) > 0.0)
                ans++;
            ans*=c;
        }
        printf("%.4lf\n",ans);
    }

    return 0;
}
