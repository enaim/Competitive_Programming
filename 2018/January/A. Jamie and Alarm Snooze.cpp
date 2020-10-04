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

    int x,r,a,b,z,temp,cnt;
    while(3==scanf("%d%d%d",&x,&a,&b))
    {
        cnt = 0;
        r  = 0;
        while(true)
        {
            temp = a;
            while(temp!=0)
            {
                z = temp%10;
                temp/=10;
                if(z==7)
                {
                    r = 1;
                    break;
                }
            }
            temp = b;
            while(temp!=0)
            {
                z = temp%10;
                temp/=10;
                if(z==7)
                {
                    r = 1;
                    break;
                }
            }
            if(r==1)
                break;

            if(b-x<0)
            {
                b = b-x+60;
                a--;
            }
            else
                b = b-x;

            cnt++;

            if(a<0)
                a = 23;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
