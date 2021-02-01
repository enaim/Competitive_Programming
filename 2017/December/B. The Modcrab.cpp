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

int ar[100000];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int h1,a1,c1,h2,a2,cnt;
    while(5==scanf("%d%d%d%d%d",&h1,&a1,&c1,&h2,&a2))
    {
        cnt = 0;
        while(h2>0)
        {
            if(h2<=a1)
            {
                h2=0;
                ar[cnt] = 1;
            }
            else if(h1>a2)
            {
                h2-=a1;
                h1-=a2;
                ar[cnt]=1;
            }
            else
            {
                h1+=(c1-a2);
                ar[cnt]=2;
            }
            cnt++;
        }
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++)
        {
            if(ar[i] == 1)
                printf("STRIKE\n");
            else
                printf("HEAL\n");
        }
    }

    return 0;
}
