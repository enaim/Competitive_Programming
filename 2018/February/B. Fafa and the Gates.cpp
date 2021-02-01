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

struct node{
    int x,y;
};
node ar[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[100010];
    int cnt,n,z,i;
    while(1==scanf("%d",&n))
    {
        scanf("%s",str);

        if(str[0]=='U')
        {
            z = 0;
            ar[0].x = 0;
            ar[0].y = 1;
        }
        else
        {
            z = 1;
            ar[0].x = 1;
            ar[0].y = 0;
        }
        cnt = 0;
        for(i=1;i<n;i++)
        {
            if(str[i]=='U')
            {
                ar[i].x = ar[i-1].x;
                ar[i].y = ar[i-1].y + 1;
            }
            else
            {
                ar[i].x = ar[i-1].x + 1;
                ar[i].y = ar[i-1].y;
            }
            if(ar[i-1].x == ar[i-1].y)
            {
                if(z==0)
                {
                    if(str[i]=='R')
                    {
                        z = 1;
                        cnt++;
                    }
                }
                else
                {
                    if(str[i]=='U')
                    {
                        z = 0;
                        cnt++;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
