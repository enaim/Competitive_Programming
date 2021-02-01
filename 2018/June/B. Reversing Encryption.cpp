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
    int i,j,x,n;
    char str[110],temp;
    while(1==scanf("%d",&n))
    {
        scanf("%s",str);
        for(int i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                x = i;
                j = 1;
                while(j<=i/2)
                {
                    temp = str[x-j];
                    str[x-j] = str[j-1];
                    str[j-1]  = temp;
                    j++;
                }
            }
        }
        printf("%s\n",str);
    }

    return 0;
}
