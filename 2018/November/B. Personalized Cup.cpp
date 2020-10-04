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
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

    char str[110];
    int i,j,k,x,len,n,a,b,t,l;

    while(1==scanf("%s",str))
    {
        len = strlen(str);
        x = (len+19)/20;
        for(j=20;j>=1;j--)
        {
            if((len+(j-1))/j>x)
                break;
        }
        j++;
        int cnt = 0;

        int z = x*j;
        z = z-len;
        int t = z/x;
        a  = z%x;
        if(a>0)
        {
            t++;
            b = 1;
        }
        int f = 0;
        cout<<x<<" "<<j<<endl;
        for(i=0;i<x;i++)
        {
            int l = 0;
            if(f<z)
            {
                for(l=0;l<t;l++)
                {
                    printf("*");
                    f++;
                }
                a--;
            }
            if(b && !a)
                t--;
            for(k=l;k<j;k++)
            {
                if(cnt<len)
                {
                    printf("%c",str[cnt]);
                    cnt++;
                }
                else
                    printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
