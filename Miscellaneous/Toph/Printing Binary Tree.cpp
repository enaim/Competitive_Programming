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

    int n,j,k,total,half,i,step,cnt,ks = 1;;
    while(1==scanf("%d",&n))
    {
        ks++;
        for(i=1;i<=20;i++)
            if(pow(2,i)==n+1)
                step = i;

        half = n;
        for(k=1;k<=step;k++)
        {
            half = half/2;
            cnt = 0;
            total = pow(2,k-1);

            for(j=1;j<=half;j++)
                printf("-");

            while(true)
            {
                printf("O");
                cnt++;

                if(total == cnt)
                {
                    printf("\n");
                    break;
                }
                for(j=1;j<=(half*2)+1;j++)
                    printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}
