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
typedef pair<int,int>pii;

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
    int a,b,c,temp,ks,cnt,x;
    while(3==scanf("%d%d%d",&a,&b,&c))
    {
        cnt = 0;
        ks = 1;
        temp = -1;
        while(ks!= 100000)
        {
            a*=10;
            cnt++;
            x = a/b;
            if(x==c && temp == -1)
                temp = cnt;
            a = a%b;
            ks++;
        }
        if(temp == -1)
            printf("-1\n");
        else
            printf("%d\n",temp);
    }

    return 0;
}
