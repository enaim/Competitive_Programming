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

    int i,k;
    while(1==scanf("%d",&k))
    {
        if(k==1)
            printf("6\n");
        else if(k>36)
            printf("-1\n");
        else
        {
            if(k%2==0)
            {
                for(i=1;i<=k/2;i++)
                    printf("8");
                printf("\n");
            }
            else
            {
                for(i=1;i<=k/2;i++)
                    printf("8");
                printf("0\n");
            }
        }
    }

    return 0;
}
