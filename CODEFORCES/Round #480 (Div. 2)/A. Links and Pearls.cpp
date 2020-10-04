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

    char str[1010];
    int i,sum1,sum2,len;
    while(1==scanf("%s",str))
    {
        len = strlen(str);
        sum1 = sum2 = 0;
        for(i=0;i<len;i++)
        {
            if(str[i]=='o')
                sum1++;
            else
                sum2++;
        }
        if(sum1==0)
            printf("YES\n");
        else if(sum2%sum1==0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
