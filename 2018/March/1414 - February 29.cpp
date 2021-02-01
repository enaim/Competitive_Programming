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

bool Leap_Year(int n)
{
    if((n%4==0 && n%100 !=0) || n%400==0)
        return true;
    return false;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    string m1,m2,s;
    int d1,d2,y1,y2,cnt,x1,x2,i;
    while(tks--)
    {
        cin>>m1>>d1>>s>>y1;
        cin>>m2>>d2>>s>>y2;

        cnt = 0;
        if(!(m1 == "January" || m1 == "February"))
            y1++;
        if(m2 == "January" || (m2 == "February" && d2 != 29))
            y2--;

        x1 = y1/400;
        x1 = x1*400 + 400;
        x2 = y2/400;
        x2 = x2*400;

        for(i=y1;i<=x1 && i<=y2;i++)
        {
            if(Leap_Year(i))
                cnt++;
        }

        if(x2>x1)
        {
            for(i=x2+1;i<=y2;i++)
            {
                if(Leap_Year(i))
                    cnt++;
            }
        }
        if(x1>y1 && x2<y2 && x1<x2)
        {
            x1/=400;
            x2/=400;
            cnt += ((x2-x1)*97);
        }

        printf("Case %d: %d\n",ks++,cnt);
    }

    return 0;
}
